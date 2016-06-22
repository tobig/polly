; RUN: opt %loadPolly -polly-scops \
; RUN:     -polly-allow-nonaffine-branches -polly-allow-nonaffine-loops \
; RUN:     -analyze < %s | FileCheck %s
; RUN: opt %loadPolly -polly-scops -polly-allow-nonaffine-branches \
; RUN:     -polly-process-unprofitable=false \
; RUN:     -polly-allow-nonaffine-loops -analyze < %s | FileCheck %s \
; RUN:     --check-prefix=PROFIT


; RUN: opt %loadPolly -polly-scops -polly-detect-reductions \
; RUN:                -polly-allow-nonaffine-branches \
; RUN:                \
; RUN:                -polly-allow-nonaffine-loops -analyze < %s \
; RUN:                -polly-detect-reductions=false \
; RUN: | FileCheck %s -check-prefix=NO-REDUCTION
;
;    void f(int *A, int *C) {
;      for (int i = 0; i < 1024; i++) {
;        while (C[i])
;          A[i]++;
;      }
;    }
;
; CHECK:    Function: f
; CHECK:    Region: %bb1---%bb12
; CHECK:    Max Loop Depth:  1
; CHECK:    Statements {
; CHECK:      Stmt_bb3__TO__bb10
; CHECK:            Domain :=
; CHECK:                { Stmt_bb3__TO__bb10[i0] :
; CHECK-DAG:               i0 >= 0
; CHECK-DAG:             and
; CHECK-DAG:               i0 <= 1023
; CHECK:                }
; CHECK:            Schedule :=
; CHECK:                { Stmt_bb3__TO__bb10[i0] -> [i0] };
; CHECK:            ReadAccess := [Reduction Type: NONE] [Scalar: 0]
; CHECK:                { Stmt_bb3__TO__bb10[i0] -> MemRef_C[i0] };
; CHECK:            ReadAccess := [Reduction Type: +] [Scalar: 0]
; CHECK:                { Stmt_bb3__TO__bb10[i0] -> MemRef_A[i0] };
; CHECK:            MayWriteAccess :=  [Reduction Type: +] [Scalar: 0]
; CHECK:                { Stmt_bb3__TO__bb10[i0] -> MemRef_A[i0] };
; CHECK:    }

; PROFIT-NOT: Statements

; NO-REDUCTION-NOT: Reduction Type: +

target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"

define void @f(i32* %A, i32* %C) {
bb:
  br label %bb1

bb1:                                              ; preds = %bb11, %bb
  %indvars.iv = phi i64 [ %indvars.iv.next, %bb11 ], [ 0, %bb ]
  %exitcond = icmp ne i64 %indvars.iv, 1024
  br i1 %exitcond, label %bb2, label %bb12

bb2:                                              ; preds = %bb1
  br label %bb3

bb3:                                              ; preds = %bb6, %bb2
  %tmp = getelementptr inbounds i32, i32* %C, i64 %indvars.iv
  %tmp4 = load i32, i32* %tmp, align 4
  %tmp5 = icmp eq i32 %tmp4, 0
  br i1 %tmp5, label %bb10, label %bb6

bb6:                                              ; preds = %bb3
  %tmp7 = getelementptr inbounds i32, i32* %A, i64 %indvars.iv
  %tmp8 = load i32, i32* %tmp7, align 4
  %tmp9 = add nsw i32 %tmp8, 1
  store i32 %tmp9, i32* %tmp7, align 4
  br label %bb3

bb10:                                             ; preds = %bb3
  br label %bb11

bb11:                                             ; preds = %bb10
  %indvars.iv.next = add nuw nsw i64 %indvars.iv, 1
  br label %bb1

bb12:                                             ; preds = %bb1
  ret void
}