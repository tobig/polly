; RUN: opt %loadPolly -polly-opt-isl -polly-ast -analyze \
; RUN: -polly-tapiropt < %s | FileCheck %s
;
;    #define N 1024
;
;    void add(float A[][N]) {
;      for (long i = 0; i < N; i++)
;        for (long j = 0; j < N; j++)
;          A[i][j] += 42;
;    }


; CHECK:          // Tapir - Tiles
; CHECK-NEXT:     for (int c0 = 0; c0 <= 63; c0 += 1)
; CHECK-NEXT:       for (int c1 = 0; c1 <= 127; c1 += 1) {
; CHECK-NEXT:         // Tapir - Points
; CHECK-NEXT:         for (int c2 = 0; c2 <= 15; c2 += 1)
; CHECK-NEXT:           for (int c3 = 0; c3 <= 7; c3 += 1)
; CHECK-NEXT:             Stmt_for_body4(16 * c0 + c2, 8 * c1 + c3);
; CHECK-NEXT:       }

;
source_filename = "/tmp/test.c"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

define dso_local void @add([1024 x float]* %A) {
entry:
  br label %for.cond

for.cond:                                         ; preds = %for.inc6, %entry
  %i.0 = phi i64 [ 0, %entry ], [ %inc7, %for.inc6 ]
  %exitcond1 = icmp ne i64 %i.0, 1024
  br i1 %exitcond1, label %for.body, label %for.cond.cleanup

for.cond.cleanup:                                 ; preds = %for.cond
  br label %for.end8

for.body:                                         ; preds = %for.cond
  br label %for.cond1

for.cond1:                                        ; preds = %for.inc, %for.body
  %j.0 = phi i64 [ 0, %for.body ], [ %inc, %for.inc ]
  %exitcond = icmp ne i64 %j.0, 1024
  br i1 %exitcond, label %for.body4, label %for.cond.cleanup3

for.cond.cleanup3:                                ; preds = %for.cond1
  br label %for.end

for.body4:                                        ; preds = %for.cond1
  %arrayidx5 = getelementptr inbounds [1024 x float], [1024 x float]* %A, i64 %i.0, i64 %j.0
  %tmp = load float, float* %arrayidx5, align 4, !tbaa !2
  %add = fadd float %tmp, 4.200000e+01
  store float %add, float* %arrayidx5, align 4, !tbaa !2
  br label %for.inc

for.inc:                                          ; preds = %for.body4
  %inc = add nuw nsw i64 %j.0, 1
  br label %for.cond1

for.end:                                          ; preds = %for.cond.cleanup3
  br label %for.inc6

for.inc6:                                         ; preds = %for.end
  %inc7 = add nuw nsw i64 %i.0, 1
  br label %for.cond

for.end8:                                         ; preds = %for.cond.cleanup
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
