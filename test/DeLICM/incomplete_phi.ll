; RUN: opt %loadPolly -polly-flatten-schedule -polly-delicm -polly-scops -analyze < %s | FileCheck %s
;
target datalayout = "e-m:x-p:32:32-i64:64-f80:32-n8:16:32-a:0:32-S32"

define void @func(double* noalias nonnull %C) {
entry:
  br label %outer.for


    outer.for:
      %i = phi i32 [0, %entry], [%i.inc, %outer.inc]
      %i.cmp = icmp slt i32 %i, 3
      br i1 %i.cmp, label %outer.body, label %outer.exit

    outer.body:
      br label %inner.for

        inner.for:
          %phi = phi double [0.0, %outer.body], [%sum, %inner.inc]
          %j = phi i32 [0, %outer.body], [%j.inc, %inner.inc]
          %j.cmp = icmp slt i32 %j, 3
          br i1 %j.cmp, label %inner.body, label %inner.exit

        inner.body:
          %sum = fadd double %phi, 1.0
          br label %inner.inc

        inner.inc:
          %j.inc = add nuw nsw i32 %j, 1
          br label %inner.for

        inner.exit:
          %C_i = getelementptr inbounds double, double* %C, i32 %i
          store double %phi, double* %C_i
          br label %outer.inc

    outer.inc:
      %i.inc = add nuw nsw i32 %i, 1
      br label %outer.for

    outer.exit:
      br label %return


return:
  ret void
}


;
; 0) Stmt_outer_body[0]
;
;
; 1) Stmt_inner_for[0, 0]
; 2) Stmt_inner_body[0, 0]
; 3) Stmt_inner_inc[0, 0]
;
; 4) Stmt_inner_for[0, 1]
; 5) Stmt_inner_body[0, 1]
; 6) Stmt_inner_inc[0, 1]
;
; 7) Stmt_inner_for[0, 2]
; 8) Stmt_inner_body[0, 2]
; 9) Stmt_inner_inc[0, 2]
;
;10) Stmt_inner_for[0, 3]
;
;
;11) Stmt_inner_exit[1]
;12) Stmt_outer_body[1]
;
;
;13) Stmt_inner_for[1, 0]
;14) Stmt_inner_body[1, 0]
;15) Stmt_inner_inc[1, 0]
;
;16) Stmt_inner_for[1, 1]
;17) Stmt_inner_body[1, 1]
;18) Stmt_inner_inc[1, 1]
;
;19) Stmt_inner_for[1, 2]
;20) Stmt_inner_body[1, 2]
;21) Stmt_inner_inc[1, 2]
;
;22) Stmt_inner_for[1, 3]
;
;
;23) Stmt_inner_exit[1]
;24) Stmt_outer_body[2]
;
;25) Stmt_inner_for[2, 0]
;26) Stmt_inner_body[2, 0]
;27) Stmt_inner_inc[2, 0]
;
;28) Stmt_inner_for[2, 1]
;29) Stmt_inner_body[2, 1]
;30) Stmt_inner_inc[2, 1]
;
;31) Stmt_inner_for[2, 2]
;32) Stmt_inner_body[2, 2]
;33) Stmt_inner_inc[2, 2]
;
;34) Stmt_inner_for[2, 3]
;
;
;35) Stmt_inner_exit[0]


; CHECK:      After accesses {
; CHECK-NEXT:     Stmt_outer_body
; CHECK-NEXT:             MustWriteAccess :=    [Reduction Type: NONE] [Scalar: 1]
; CHECK-NEXT:                 { Stmt_outer_body[i0] -> MemRef_phi__phi[] };
; CHECK-NEXT:            new: { Stmt_outer_body[i0] -> MemRef_C[i0] : 0 <= i0 <= 2 };
; CHECK-NEXT:     Stmt_inner_for
; CHECK-NEXT:             ReadAccess :=    [Reduction Type: NONE] [Scalar: 1]
; CHECK-NEXT:                 { Stmt_inner_for[i0, i1] -> MemRef_phi__phi[] };
; CHECK-NEXT:            new: { Stmt_inner_for[i0, i1] -> MemRef_C[i0] : i0 <= 2 and i1 >= 0 and 4 - 4i0 <= i1 <= 3; Stmt_inner_for[0, i1] -> MemRef_C[0] : 0 <= i1 <= 3 };
; CHECK-NEXT:             MustWriteAccess :=    [Reduction Type: NONE] [Scalar: 1]
; CHECK-NEXT:                 { Stmt_inner_for[i0, i1] -> MemRef_phi[] };
; CHECK-NEXT:            new: { Stmt_inner_for[i0, i1] -> MemRef_C[i0] : i1 >= 0 and 4 - 4i0 <= i1 <= 11 - 4i0 and i1 <= 3; Stmt_inner_for[0, i1] -> MemRef_C[0] : 0 <= i1 <= 3 };
; CHECK-NEXT:     Stmt_inner_body
; CHECK-NEXT:             MustWriteAccess :=    [Reduction Type: NONE] [Scalar: 1]
; CHECK-NEXT:                 { Stmt_inner_body[i0, i1] -> MemRef_sum[] };
; CHECK-NEXT:            new: { Stmt_inner_body[i0, i1] -> MemRef_C[i0] : i1 >= 0 and 3 - 4i0 <= i1 <= 11 - 4i0 and i1 <= 2; Stmt_inner_body[0, i1] -> MemRef_C[0] : 0 <= i1 <= 2 };
; CHECK-NEXT:             ReadAccess :=    [Reduction Type: NONE] [Scalar: 1]
; CHECK-NEXT:                 { Stmt_inner_body[i0, i1] -> MemRef_phi[] };
; CHECK-NEXT:            new: { Stmt_inner_body[i0, i1] -> MemRef_C[i0] : i1 >= 0 and 4 - 4i0 <= i1 <= 10 - 4i0 and i1 <= 2; Stmt_inner_body[0, i1] -> MemRef_C[0] : 0 <= i1 <= 2 };
; CHECK-NEXT:     Stmt_inner_inc
; CHECK-NEXT:             ReadAccess :=    [Reduction Type: NONE] [Scalar: 1]
; CHECK-NEXT:                 { Stmt_inner_inc[i0, i1] -> MemRef_sum[] };
; CHECK-NEXT:            new: { Stmt_inner_inc[i0, i1] -> MemRef_C[i0] : i1 >= 0 and 3 - 4i0 <= i1 <= 9 - 4i0 and i1 <= 2; Stmt_inner_inc[0, i1] -> MemRef_C[0] : 0 <= i1 <= 2; Stmt_inner_inc[2, 2] -> MemRef_C[2] };
; CHECK-NEXT:             MustWriteAccess :=    [Reduction Type: NONE] [Scalar: 1]
; CHECK-NEXT:                 { Stmt_inner_inc[i0, i1] -> MemRef_phi__phi[] };
; CHECK-NEXT:            new: { Stmt_inner_inc[i0, i1] -> MemRef_C[i0] : 0 <= i0 <= 2 and 0 <= i1 <= 2 };
; CHECK-NEXT:     Stmt_inner_exit
; CHECK-NEXT:             MustWriteAccess :=    [Reduction Type: NONE] [Scalar: 0]
; CHECK-NEXT:                 { Stmt_inner_exit[i0] -> MemRef_C[i0] };
; CHECK-NEXT:             ReadAccess :=    [Reduction Type: NONE] [Scalar: 1]
; CHECK-NEXT:                 { Stmt_inner_exit[i0] -> MemRef_phi[] };
; CHECK-NEXT:            new: { Stmt_inner_exit[i0] -> MemRef_C[i0] : 0 <= i0 <= 2 };
; CHECK-NEXT: }
