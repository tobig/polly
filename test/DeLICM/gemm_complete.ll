; RUN: opt %loadPolly -basicaa -loop-rotate -licm -polly-delicm -analyze < %s | FileCheck %s
;
; dgemm kernel
; C := alpha*A*B + beta*C
; C[ni][nj]
; A[ni][nk]
; B[nk][nj]

target datalayout = "e-m:x-p:32:32-i64:64-f80:32-n8:16:32-a:0:32-S32"

define void @gemm(i32 %ni, i32 %nj, i32 %nk, double %alpha, double %beta, double* noalias nonnull %C, double* noalias nonnull %A, double* noalias nonnull %B) {
entry:
  br label %ni.for

ni.for:
  %i = phi i32 [0, %entry], [%i.inc, %ni.inc]
  %i.cmp = icmp slt i32 %i, %ni
  br i1 %i.cmp, label %nj.for, label %ni.exit

  nj.for:
    %j = phi i32 [0, %ni.for], [%j.inc, %nj.inc]
    %j.cmp = icmp slt i32 %j, %nj
    br i1 %j.cmp, label %nj_beta, label %nj.exit

    nj_beta:
     %c_stride = mul nsw i32 %i, %nj
     %c_idx_i = getelementptr inbounds double, double* %C, i32 %c_stride
     %c_idx_ij = getelementptr inbounds double, double* %c_idx_i, i32 %j

     ; C[i][j] *= beta
     %c = load double, double* %c_idx_ij
     %c_beta = fmul double %c, %beta
     store double %c_beta, double* %c_idx_ij

     br label %nk.for

    nk.for:
      %k = phi i32 [0, %nj_beta], [%k.inc, %nk.inc]
      %k.cmp = icmp slt i32 %k, %nk
      br i1 %k.cmp, label %nk_alpha, label %nk.exit

      nk_alpha:
        %a_stride = mul nsw i32 %i, %nk
        %a_idx_i = getelementptr inbounds double, double* %A, i32 %a_stride
        %a_idx_ik = getelementptr inbounds double, double* %a_idx_i, i32 %k

        %b_stride = mul nsw i32 %k, %nj
        %b_idx_k = getelementptr inbounds double, double* %B, i32 %b_stride
        %b_idx_kj = getelementptr inbounds double, double* %b_idx_k, i32 %j

        ; C[i][j] += alpha * A[i][k] * B[k][j]
        %a = load double, double* %a_idx_ik
        %b = load double, double* %b_idx_kj
        %beta_c = load double, double* %c_idx_ij

        %alpha_a = fmul double %a, %alpha
        %alpha_a_b = fmul double %alpha_a, %b
        %beta_c_alpha_a_b = fadd double %beta_c, %alpha_a_b

        store double %beta_c_alpha_a_b, double* %c_idx_ij

        br label %nk.inc

    nk.inc:
      %k.inc = add nuw nsw i32 %k, 1
      br label %nk.for

    nk.exit:
      br label %nj.inc

  nj.inc:
    %j.inc = add nuw nsw i32 %j, 1
    br label %nj.for

  nj.exit:
    br label %ni.inc

ni.inc:
  %i.inc = add nuw nsw i32 %i, 1
  br label %ni.for

ni.exit:
  br label %return

return:
  ret void
}


; CHECK:      After accesses {
; CHECK-NEXT:     Stmt_nj_beta
; CHECK-NEXT:             ReadAccess :=    [Reduction Type: NONE] [Scalar: 0]
; CHECK-NEXT:                 [nj, nk, ni] -> { Stmt_nj_beta[i0, i1] -> MemRef_C[i0, i1] };
; CHECK-NEXT:             ReadAccess :=    [Reduction Type: NONE] [Scalar: 1]
; CHECK-NEXT:                 [nj, nk, ni] -> { Stmt_nj_beta[i0, i1] -> MemRef_beta[] };
; CHECK-NEXT:             MustWriteAccess :=    [Reduction Type: NONE] [Scalar: 0]
; CHECK-NEXT:                 [nj, nk, ni] -> { Stmt_nj_beta[i0, i1] -> MemRef_C[i0, i1] };
; CHECK-NEXT:     Stmt_nk_alpha_lr_ph
; CHECK-NEXT:             ReadAccess :=    [Reduction Type: NONE] [Scalar: 0]
; CHECK-NEXT:                 [nj, nk, ni] -> { Stmt_nk_alpha_lr_ph[i0, i1] -> MemRef_C[i0, i1] };
; CHECK-NEXT:             MustWriteAccess :=    [Reduction Type: NONE] [Scalar: 1]
; CHECK-NEXT:                 [nj, nk, ni] -> { Stmt_nk_alpha_lr_ph[i0, i1] -> MemRef_beta_c_alpha_a_b3__phi[] };
; CHECK-NEXT:            new: [nj, nk, ni] -> { Stmt_nk_alpha_lr_ph[i0, i1] -> MemRef_C[i0, i1] : nk > 0 and 0 <= i0 < ni and 0 <= i1 < nj; Stmt_nk_alpha_lr_ph[0, i1] -> MemRef_C[0, i1] : nk > 0 and ni <= 0 and 0 <= i1 < nj };
; CHECK-NEXT:     Stmt_nk_alpha
; CHECK-NEXT:             MustWriteAccess :=    [Reduction Type: NONE] [Scalar: 1]
; CHECK-NEXT:                 [nj, nk, ni] -> { Stmt_nk_alpha[i0, i1, i2] -> MemRef_beta_c_alpha_a_b[] };
; CHECK-NEXT:            new: [nj, nk, ni] -> { Stmt_nk_alpha[i0, i1, i2] -> MemRef_C[i0, i1] : 0 <= i0 < ni and 0 <= i1 < nj and 0 <= i2 < nk; Stmt_nk_alpha[0, i1, i2] -> MemRef_C[0, i1] : ni <= 0 and 0 <= i1 < nj and 0 <= i2 < nk };
; CHECK-NEXT:             ReadAccess :=    [Reduction Type: NONE] [Scalar: 1]
; CHECK-NEXT:                 [nj, nk, ni] -> { Stmt_nk_alpha[i0, i1, i2] -> MemRef_beta_c_alpha_a_b3__phi[] };
; CHECK-NEXT:            new: [nj, nk, ni] -> { Stmt_nk_alpha[i0, i1, i2] -> MemRef_C[i0, i1] : 0 <= i0 < ni and 0 <= i1 < nj and 0 <= i2 < nk; Stmt_nk_alpha[0, i1, i2] -> MemRef_C[0, i1] : ni <= 0 and 0 <= i1 < nj and 0 <= i2 < nk };
; CHECK-NEXT:             ReadAccess :=    [Reduction Type: NONE] [Scalar: 0]
; CHECK-NEXT:                 [nj, nk, ni] -> { Stmt_nk_alpha[i0, i1, i2] -> MemRef_A[i0, i2] };
; CHECK-NEXT:             ReadAccess :=    [Reduction Type: NONE] [Scalar: 0]
; CHECK-NEXT:                 [nj, nk, ni] -> { Stmt_nk_alpha[i0, i1, i2] -> MemRef_B[i2, i1] };
; CHECK-NEXT:             ReadAccess :=    [Reduction Type: NONE] [Scalar: 1]
; CHECK-NEXT:                 [nj, nk, ni] -> { Stmt_nk_alpha[i0, i1, i2] -> MemRef_alpha[] };
; CHECK-NEXT:     Stmt_nk_inc
; CHECK-NEXT:             ReadAccess :=    [Reduction Type: NONE] [Scalar: 1]
; CHECK-NEXT:                 [nj, nk, ni] -> { Stmt_nk_inc[i0, i1, i2] -> MemRef_beta_c_alpha_a_b[] };
; CHECK-NEXT:            new: [nj, nk, ni] -> { Stmt_nk_inc[i0, i1, i2] -> MemRef_C[i0, i1] : 0 <= i0 < ni and 0 <= i1 < nj and 0 <= i2 < nk; Stmt_nk_inc[0, i1, i2] -> MemRef_C[0, i1] : ni <= 0 and 0 <= i1 < nj and 0 <= i2 < nk };
; CHECK-NEXT:             MustWriteAccess :=    [Reduction Type: NONE] [Scalar: 1]
; CHECK-NEXT:                 [nj, nk, ni] -> { Stmt_nk_inc[i0, i1, i2] -> MemRef_beta_c_alpha_a_b3__phi[] };
; CHECK-NEXT:            new: [nj, nk, ni] -> { Stmt_nk_inc[i0, i1, i2] -> MemRef_C[i0, i1] : 0 <= i0 < ni and 0 <= i1 < nj and 0 <= i2 < nk; Stmt_nk_inc[0, i1, i2] -> MemRef_C[0, i1] : ni <= 0 and 0 <= i1 < nj and 0 <= i2 < nk };
; CHECK-NEXT:             MustWriteAccess :=    [Reduction Type: NONE] [Scalar: 1]
; CHECK-NEXT:                 [nj, nk, ni] -> { Stmt_nk_inc[i0, i1, i2] -> MemRef_beta_c_alpha_a_b_lcssa__phi[] };
; CHECK-NEXT:            new: [nj, nk, ni] -> { Stmt_nk_inc[i0, i1, i2] -> MemRef_C[i0, i1] : 0 <= i0 < ni and 0 <= i1 < nj and 0 <= i2 < nk; Stmt_nk_inc[0, i1, i2] -> MemRef_C[0, i1] : ni <= 0 and 0 <= i1 < nj and 0 <= i2 < nk };
; CHECK-NEXT:     Stmt_nk_for_nk_exit_crit_edge
; CHECK-NEXT:             ReadAccess :=    [Reduction Type: NONE] [Scalar: 1]
; CHECK-NEXT:                 [nj, nk, ni] -> { Stmt_nk_for_nk_exit_crit_edge[i0, i1] -> MemRef_beta_c_alpha_a_b_lcssa__phi[] };
; CHECK-NEXT:            new: [nj, nk, ni] -> { Stmt_nk_for_nk_exit_crit_edge[i0, i1] -> MemRef_C[i0, i1] : nk > 0 and 0 <= i0 < ni and 0 <= i1 < nj; Stmt_nk_for_nk_exit_crit_edge[0, i1] -> MemRef_C[0, i1] : nk > 0 and ni <= 0 and 0 <= i1 < nj };
; CHECK-NEXT:             MustWriteAccess :=    [Reduction Type: NONE] [Scalar: 0]
; CHECK-NEXT:                 [nj, nk, ni] -> { Stmt_nk_for_nk_exit_crit_edge[i0, i1] -> MemRef_C[i0, i1] };
; CHECK-NEXT: }
