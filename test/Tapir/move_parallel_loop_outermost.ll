; RUN: opt %loadPolly -polly-opt-isl -polly-ast -analyze \
; RUN: -polly-tapiropt -polly-parallel < %s | FileCheck %s
;
;    #define N 1024
;
;    void add(float A[][N]) {
;      for (long k = 0; k < N; k++)
;        for (long i = 0; i < N; i++)
;          for (long j = 0; j < N; j++)
;            A[i][j] += 42;
;    }


; CHECK:          // Tapir - Tiles
; CHECK-NEXT:     #pragma omp parallel for
; CHECK-NEXT:     for (int c0 = 0; c0 <= 63; c0 += 1)
; CHECK-NEXT:       for (int c1 = 0; c1 <= 127; c1 += 1)
; CHECK-NEXT:         // Tapir Base Case
; CHECK-NEXT:         for (int c2 = 0; c2 <= 127; c2 += 1) {
; CHECK-NEXT:           // Tapir - Points
; CHECK-NEXT:           for (int c3 = 0; c3 <= 15; c3 += 1)
; CHECK-NEXT:             for (int c4 = 0; c4 <= 7; c4 += 1)
; CHECK-NEXT:               #pragma minimal dependence distance: 1
; CHECK-NEXT:               for (int c5 = 0; c5 <= 7; c5 += 1)
; CHECK-NEXT:                 Stmt_for_body8(8 * c2 + c5, 16 * c0 + c3, 8 * c1 + c4);
; CHECK-NEXT:         }

source_filename = "/tmp/test2.c"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

define dso_local void @add([1024 x float]* %A) {
entry:
  br label %for.cond

for.cond:                                         ; preds = %for.inc13, %entry
  %k.0 = phi i64 [ 0, %entry ], [ %inc14, %for.inc13 ]
  %exitcond2 = icmp ne i64 %k.0, 1024
  br i1 %exitcond2, label %for.body, label %for.cond.cleanup

for.cond.cleanup:                                 ; preds = %for.cond
  br label %for.end15

for.body:                                         ; preds = %for.cond
  br label %for.cond1

for.cond1:                                        ; preds = %for.inc10, %for.body
  %i.0 = phi i64 [ 0, %for.body ], [ %inc11, %for.inc10 ]
  %exitcond1 = icmp ne i64 %i.0, 1024
  br i1 %exitcond1, label %for.body4, label %for.cond.cleanup3

for.cond.cleanup3:                                ; preds = %for.cond1
  br label %for.end12

for.body4:                                        ; preds = %for.cond1
  br label %for.cond5

for.cond5:                                        ; preds = %for.inc, %for.body4
  %j.0 = phi i64 [ 0, %for.body4 ], [ %inc, %for.inc ]
  %exitcond = icmp ne i64 %j.0, 1024
  br i1 %exitcond, label %for.body8, label %for.cond.cleanup7

for.cond.cleanup7:                                ; preds = %for.cond5
  br label %for.end

for.body8:                                        ; preds = %for.cond5
  %arrayidx9 = getelementptr inbounds [1024 x float], [1024 x float]* %A, i64 %i.0, i64 %j.0
  %tmp = load float, float* %arrayidx9, align 4, !tbaa !2
  %add = fadd float %tmp, 4.200000e+01
  store float %add, float* %arrayidx9, align 4, !tbaa !2
  br label %for.inc

for.inc:                                          ; preds = %for.body8
  %inc = add nuw nsw i64 %j.0, 1
  br label %for.cond5

for.end:                                          ; preds = %for.cond.cleanup7
  br label %for.inc10

for.inc10:                                        ; preds = %for.end
  %inc11 = add nuw nsw i64 %i.0, 1
  br label %for.cond1

for.end12:                                        ; preds = %for.cond.cleanup3
  br label %for.inc13

for.inc13:                                        ; preds = %for.end12
  %inc14 = add nuw nsw i64 %k.0, 1
  br label %for.cond

for.end15:                                        ; preds = %for.cond.cleanup
  ret void
}

declare void @llvm.lifetime.start.p0i8(i64, i8* nocapture)

declare void @llvm.lifetime.end.p0i8(i64, i8* nocapture)


!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{!"clang version 7.0.0 (trunk 327993) (llvm/trunk 327997)"}
!2 = !{!3, !3, i64 0}
!3 = !{!"float", !4, i64 0}
!4 = !{!"omnipotent char", !5, i64 0}
!5 = !{!"Simple C/C++ TBAA"}
