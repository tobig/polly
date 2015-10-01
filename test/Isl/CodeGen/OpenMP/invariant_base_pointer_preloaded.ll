; RUN: opt %loadPolly -polly-codegen -polly-parallel \
; RUN: -polly-parallel-force -polly-detect-unprofitable -S < %s | FileCheck %s
;
; Test to verify that we hand down the preloaded A[0] to the OpenMP subfunction.
;
;    void f(float *A) {
;      for (int i = 1; i < 1000; i++)
;        A[i] += A[0];
;    }
;
; CHECK:  %polly.subfn.storeaddr.polly.access.A.load = getelementptr inbounds { float*, float }, { float*, float }* %polly.par.userContext, i32 0, i32 1
; CHECK:  store float %polly.access.A.load, float* %polly.subfn.storeaddr.polly.access.A.load
;
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"

define void @f(float* nocapture %A) {
entry:
  br label %for.body

for.cond.cleanup:                                 ; preds = %for.body
  ret void

for.body:                                         ; preds = %for.body, %entry
  %indvars.iv = phi i64 [ 1, %entry ], [ %indvars.iv.next, %for.body ]
  %tmp = load float, float* %A, align 4
  %arrayidx1 = getelementptr inbounds float, float* %A, i64 %indvars.iv
  %tmp1 = load float, float* %arrayidx1, align 4
  %add = fadd float %tmp, %tmp1
  store float %add, float* %arrayidx1, align 4
  %indvars.iv.next = add nuw nsw i64 %indvars.iv, 1
  %exitcond = icmp eq i64 %indvars.iv.next, 1000
  br i1 %exitcond, label %for.cond.cleanup, label %for.body
}
