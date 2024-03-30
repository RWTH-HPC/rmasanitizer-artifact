; ModuleID = 'results-20240330-164421/PARCOACH-dynamic/hybrid/021-MPI-hybrid-section-barrier-origin-remote-yes.c.ll'
source_filename = "results-20240330-164421/PARCOACH-dynamic/hybrid/021-MPI-hybrid-section-barrier-origin-remote-yes.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct.ompi_predefined_communicator_t = type opaque
%struct.ompi_predefined_info_t = type opaque
%struct.ident_t = type { i32, i32, i32, i32, ptr }
%struct.ompi_predefined_datatype_t = type opaque

@.str = private unnamed_addr constant [35 x i8] c"MPI_THREAD_MULTIPLE not supported\0A\00", align 1, !dbg !0
@ompi_mpi_comm_world = external global %struct.ompi_predefined_communicator_t, align 1
@.str.1 = private unnamed_addr constant [49 x i8] c"Wrong number of MPI processes: %d. Expected: %d\0A\00", align 1, !dbg !7
@ompi_mpi_info_null = external global %struct.ompi_predefined_info_t, align 1
@0 = private unnamed_addr constant [112 x i8] c";results-20240330-164421/PARCOACH-dynamic/hybrid/021-MPI-hybrid-section-barrier-origin-remote-yes.c;main;66;1;;\00", align 1
@1 = private unnamed_addr constant %struct.ident_t { i32 0, i32 1026, i32 0, i32 111, ptr @0 }, align 8
@ompi_mpi_int = external global %struct.ompi_predefined_datatype_t, align 1
@2 = private unnamed_addr constant [113 x i8] c";results-20240330-164421/PARCOACH-dynamic/hybrid/021-MPI-hybrid-section-barrier-origin-remote-yes.c;main;66;21;;\00", align 1
@3 = private unnamed_addr constant %struct.ident_t { i32 0, i32 1026, i32 0, i32 112, ptr @2 }, align 8
@4 = private unnamed_addr constant %struct.ident_t { i32 0, i32 194, i32 0, i32 111, ptr @0 }, align 8
@5 = private unnamed_addr constant [113 x i8] c";results-20240330-164421/PARCOACH-dynamic/hybrid/021-MPI-hybrid-section-barrier-origin-remote-yes.c;main;64;22;;\00", align 1
@6 = private unnamed_addr constant %struct.ident_t { i32 0, i32 2, i32 0, i32 112, ptr @5 }, align 8
@7 = private unnamed_addr constant [112 x i8] c";results-20240330-164421/PARCOACH-dynamic/hybrid/021-MPI-hybrid-section-barrier-origin-remote-yes.c;main;64;1;;\00", align 1
@8 = private unnamed_addr constant %struct.ident_t { i32 0, i32 2, i32 0, i32 111, ptr @7 }, align 8
@.str.2 = private unnamed_addr constant [19 x i8] c"win_base[0] is %d\0A\00", align 1, !dbg !12
@.str.3 = private unnamed_addr constant [94 x i8] c"Process %d: Execution finished, variable contents: value = %d, value2 = %d, win_base[0] = %d\0A\00", align 1, !dbg !17
@9 = private unnamed_addr constant [99 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/021-MPI-hybrid-section-barrier-origin-remote-yes.c\00", align 1
@10 = private unnamed_addr constant [99 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/021-MPI-hybrid-section-barrier-origin-remote-yes.c\00", align 1
@11 = private unnamed_addr constant [99 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/021-MPI-hybrid-section-barrier-origin-remote-yes.c\00", align 1
@12 = private unnamed_addr constant [99 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/021-MPI-hybrid-section-barrier-origin-remote-yes.c\00", align 1
@13 = private unnamed_addr constant [99 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/021-MPI-hybrid-section-barrier-origin-remote-yes.c\00", align 1
@14 = private unnamed_addr constant [99 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/021-MPI-hybrid-section-barrier-origin-remote-yes.c\00", align 1
@15 = private unnamed_addr constant [99 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/021-MPI-hybrid-section-barrier-origin-remote-yes.c\00", align 1
@16 = private unnamed_addr constant [99 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/021-MPI-hybrid-section-barrier-origin-remote-yes.c\00", align 1
@17 = private unnamed_addr constant [99 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/021-MPI-hybrid-section-barrier-origin-remote-yes.c\00", align 1
@18 = private unnamed_addr constant [99 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/021-MPI-hybrid-section-barrier-origin-remote-yes.c\00", align 1
@19 = private unnamed_addr constant [99 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/021-MPI-hybrid-section-barrier-origin-remote-yes.c\00", align 1
@20 = private unnamed_addr constant [99 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/021-MPI-hybrid-section-barrier-origin-remote-yes.c\00", align 1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main(i32 noundef %0, ptr noundef %1) #0 !dbg !53 {
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = alloca ptr, align 8
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  %8 = alloca ptr, align 8
  %9 = alloca ptr, align 8
  %10 = alloca i32, align 4
  %11 = alloca i32, align 4
  %12 = alloca i32, align 4
  %13 = alloca i32, align 4
  %14 = alloca i32, align 4
  %15 = alloca i32, align 4
  %16 = call i32 @__kmpc_global_thread_num(ptr @6)
  store i32 0, ptr %3, align 4
  store i32 %0, ptr %4, align 4
  call void @llvm.dbg.declare(metadata ptr %4, metadata !60, metadata !DIExpression()), !dbg !61
  store ptr %1, ptr %5, align 8
  call void @llvm.dbg.declare(metadata ptr %5, metadata !62, metadata !DIExpression()), !dbg !63
  call void @llvm.dbg.declare(metadata ptr %6, metadata !64, metadata !DIExpression()), !dbg !65
  call void @llvm.dbg.declare(metadata ptr %7, metadata !66, metadata !DIExpression()), !dbg !67
  call void @llvm.dbg.declare(metadata ptr %8, metadata !68, metadata !DIExpression()), !dbg !72
  call void @llvm.dbg.declare(metadata ptr %9, metadata !73, metadata !DIExpression()), !dbg !75
  call void @llvm.dbg.declare(metadata ptr %10, metadata !76, metadata !DIExpression()), !dbg !77
  store i32 1, ptr %10, align 4, !dbg !77
  call void @llvm.dbg.declare(metadata ptr %11, metadata !78, metadata !DIExpression()), !dbg !79
  store i32 2, ptr %11, align 4, !dbg !79
  call void @llvm.dbg.declare(metadata ptr %12, metadata !80, metadata !DIExpression()), !dbg !81
  call void @llvm.dbg.declare(metadata ptr %13, metadata !82, metadata !DIExpression()), !dbg !83
  store i32 42, ptr %13, align 4, !dbg !83
  call void @llvm.dbg.declare(metadata ptr %14, metadata !84, metadata !DIExpression()), !dbg !85
  %17 = call i32 @MPI_Init_thread(ptr noundef %4, ptr noundef %5, i32 noundef 3, ptr noundef %14), !dbg !86
  %18 = load i32, ptr %14, align 4, !dbg !87
  %19 = icmp slt i32 %18, 3, !dbg !89
  br i1 %19, label %20, label %23, !dbg !90

20:                                               ; preds = %2
  %21 = call i32 (ptr, ...) @printf(ptr noundef @.str), !dbg !91
  %22 = call i32 @MPI_Abort(ptr noundef @ompi_mpi_comm_world, i32 noundef 1), !dbg !93
  br label %23, !dbg !94

23:                                               ; preds = %20, %2
  %24 = call i32 @MPI_Comm_rank(ptr noundef @ompi_mpi_comm_world, ptr noundef %6), !dbg !95
  %25 = call i32 @MPI_Comm_size(ptr noundef @ompi_mpi_comm_world, ptr noundef %7), !dbg !96
  %26 = load i32, ptr %7, align 4, !dbg !97
  %27 = icmp ne i32 %26, 2, !dbg !99
  br i1 %27, label %28, label %32, !dbg !100

28:                                               ; preds = %23
  %29 = load i32, ptr %7, align 4, !dbg !101
  %30 = call i32 (ptr, ...) @printf(ptr noundef @.str.1, i32 noundef %29, i32 noundef 2), !dbg !103
  %31 = call i32 @MPI_Abort(ptr noundef @ompi_mpi_comm_world, i32 noundef 1), !dbg !104
  br label %32, !dbg !105

32:                                               ; preds = %28, %23
  %33 = call i32 @parcoach_rma_MPI_Win_allocate(i64 40, i32 4, ptr @ompi_mpi_info_null, ptr @ompi_mpi_comm_world, ptr %9, ptr %8, i32 57, ptr @9), !dbg !106
  call void @llvm.dbg.declare(metadata ptr %15, metadata !107, metadata !DIExpression()), !dbg !109
  store i32 0, ptr %15, align 4, !dbg !109
  br label %34, !dbg !110

34:                                               ; preds = %42, %32
  %35 = load i32, ptr %15, align 4, !dbg !111
  %36 = icmp slt i32 %35, 10, !dbg !113
  br i1 %36, label %37, label %45, !dbg !114

37:                                               ; preds = %34
  %38 = load ptr, ptr %9, align 8, !dbg !115
  %39 = load i32, ptr %15, align 4, !dbg !117
  %40 = sext i32 %39 to i64, !dbg !115
  %41 = getelementptr inbounds i32, ptr %38, i64 %40, !dbg !115
  store i32 0, ptr %41, align 4, !dbg !118
  br label %42, !dbg !119

42:                                               ; preds = %37
  %43 = load i32, ptr %15, align 4, !dbg !120
  %44 = add nsw i32 %43, 1, !dbg !120
  store i32 %44, ptr %15, align 4, !dbg !120
  br label %34, !dbg !121, !llvm.loop !122

45:                                               ; preds = %34
  %46 = call i32 @parcoach_rma_MPI_Barrier(ptr @ompi_mpi_comm_world, i32 61, ptr @10), !dbg !125
  %47 = load i32, ptr %6, align 4, !dbg !126
  %48 = icmp eq i32 %47, 0, !dbg !128
  br i1 %48, label %49, label %50, !dbg !129

49:                                               ; preds = %45
  call void @__kmpc_push_num_threads(ptr @6, i32 %16, i32 2), !dbg !130
  call void (ptr, i32, ptr, ...) @__kmpc_fork_call(ptr @8, i32 1, ptr @.omp_outlined., ptr %8), !dbg !130
  br label %50, !dbg !132

50:                                               ; preds = %49, %45
  %51 = load i32, ptr %6, align 4, !dbg !133
  %52 = icmp eq i32 %51, 1, !dbg !135
  br i1 %52, label %53, label %59, !dbg !136

53:                                               ; preds = %50
  %54 = call i32 @parcoach_rma_MPI_Barrier(ptr @ompi_mpi_comm_world, i32 87, ptr @11), !dbg !137
  %55 = load ptr, ptr %9, align 8, !dbg !139
  %56 = getelementptr inbounds i32, ptr %55, i64 0, !dbg !139
  %57 = load i32, ptr %56, align 4, !dbg !139
  %58 = call i32 (ptr, ...) @printf(ptr noundef @.str.2, i32 noundef %57), !dbg !140
  br label %59, !dbg !141

59:                                               ; preds = %53, %50
  %60 = call i32 @parcoach_rma_MPI_Barrier(ptr @ompi_mpi_comm_world, i32 92, ptr @12), !dbg !142
  %61 = load i32, ptr %6, align 4, !dbg !143
  %62 = load i32, ptr %10, align 4, !dbg !144
  %63 = load i32, ptr %11, align 4, !dbg !145
  %64 = load ptr, ptr %9, align 8, !dbg !146
  %65 = getelementptr inbounds i32, ptr %64, i64 0, !dbg !146
  %66 = load i32, ptr %65, align 4, !dbg !146
  %67 = call i32 (ptr, ...) @printf(ptr noundef @.str.3, i32 noundef %61, i32 noundef %62, i32 noundef %63, i32 noundef %66), !dbg !147
  %68 = call i32 @parcoach_rma_MPI_Win_free(ptr %8, i32 100, ptr @13), !dbg !148
  %69 = call i32 @MPI_Finalize(), !dbg !149
  ret i32 0, !dbg !150
}

; Function Attrs: nocallback nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

declare i32 @MPI_Init_thread(ptr noundef, ptr noundef, i32 noundef, ptr noundef) #2

declare i32 @printf(ptr noundef, ...) #2

declare i32 @MPI_Abort(ptr noundef, i32 noundef) #2

declare i32 @MPI_Comm_rank(ptr noundef, ptr noundef) #2

declare i32 @MPI_Comm_size(ptr noundef, ptr noundef) #2

declare i32 @MPI_Win_allocate(i64 noundef, i32 noundef, ptr noundef, ptr noundef, ptr noundef, ptr noundef) #2

declare i32 @MPI_Barrier(ptr noundef) #2

; Function Attrs: noinline norecurse nounwind optnone uwtable
define internal void @.omp_outlined._debug__(ptr noalias noundef %0, ptr noalias noundef %1, ptr noundef nonnull align 8 dereferenceable(8) %2) #3 !dbg !151 {
  %4 = alloca ptr, align 8
  %5 = alloca ptr, align 8
  %6 = alloca ptr, align 8
  %7 = alloca i32, align 4
  %8 = alloca i32, align 4
  %9 = alloca i32, align 4
  %10 = alloca i32, align 4
  %11 = alloca i32, align 4
  %12 = alloca i32, align 4
  store ptr %0, ptr %4, align 8
  call void @llvm.dbg.declare(metadata ptr %4, metadata !159, metadata !DIExpression()), !dbg !160
  store ptr %1, ptr %5, align 8
  call void @llvm.dbg.declare(metadata ptr %5, metadata !161, metadata !DIExpression()), !dbg !160
  store ptr %2, ptr %6, align 8
  call void @llvm.dbg.declare(metadata ptr %6, metadata !162, metadata !DIExpression()), !dbg !163
  %13 = load ptr, ptr %6, align 8, !dbg !164
  store i32 0, ptr %7, align 4, !dbg !165
  store i32 1, ptr %8, align 4, !dbg !165
  store i32 1, ptr %9, align 4, !dbg !165
  store i32 0, ptr %10, align 4, !dbg !165
  %14 = load ptr, ptr %4, align 8, !dbg !165
  %15 = load i32, ptr %14, align 4, !dbg !165
  call void @__kmpc_for_static_init_4(ptr @1, i32 %15, i32 34, ptr %10, ptr %7, ptr %8, ptr %9, i32 1, i32 1), !dbg !167
  %16 = load i32, ptr %8, align 4, !dbg !165
  %17 = icmp slt i32 %16, 1, !dbg !165
  %18 = select i1 %17, i32 %16, i32 1, !dbg !165
  store i32 %18, ptr %8, align 4, !dbg !165
  %19 = load i32, ptr %7, align 4, !dbg !165
  store i32 %19, ptr %11, align 4, !dbg !165
  br label %20, !dbg !165

20:                                               ; preds = %37, %3
  %21 = load i32, ptr %11, align 4, !dbg !167
  %22 = load i32, ptr %8, align 4, !dbg !167
  %23 = icmp sle i32 %21, %22, !dbg !167
  br i1 %23, label %24, label %40, !dbg !165

24:                                               ; preds = %20
  %25 = load i32, ptr %11, align 4, !dbg !165
  switch i32 %25, label %36 [
    i32 0, label %26
    i32 1, label %33
  ], !dbg !165

26:                                               ; preds = %24
  call void @llvm.dbg.declare(metadata ptr %12, metadata !169, metadata !DIExpression()), !dbg !172
  store i32 42, ptr %12, align 4, !dbg !172
  %27 = load ptr, ptr %13, align 8, !dbg !173
  %28 = call i32 @parcoach_rma_MPI_Win_lock(i32 1, i32 1, i32 0, ptr %27, i32 71, ptr @14), !dbg !174
  call void @parcoach_rma_load(ptr %13, i64 64, i32 73, ptr @15), !dbg !175
  %29 = load ptr, ptr %13, align 8, !dbg !175
  %30 = call i32 @parcoach_rma_MPI_Put(ptr %12, i32 1, ptr @ompi_mpi_int, i32 1, i64 0, i32 1, ptr @ompi_mpi_int, ptr %29, i32 73, ptr @16), !dbg !176
  %31 = load ptr, ptr %13, align 8, !dbg !177
  %32 = call i32 @parcoach_rma_MPI_Win_unlock(i32 1, ptr %31, i32 74, ptr @17), !dbg !178
  br label %36, !dbg !179

33:                                               ; preds = %24
  %34 = call i32 @sleep(i32 noundef 1), !dbg !180
  %35 = call i32 @parcoach_rma_MPI_Barrier(ptr @ompi_mpi_comm_world, i32 80, ptr @18), !dbg !183
  br label %36, !dbg !184

36:                                               ; preds = %33, %26, %24
  br label %37, !dbg !184

37:                                               ; preds = %36
  call void @parcoach_rma_load(ptr %11, i64 32, i32 66, ptr @19), !dbg !167
  %38 = load i32, ptr %11, align 4, !dbg !167
  %39 = add nsw i32 %38, 1, !dbg !167
  call void @parcoach_rma_store(ptr %11, i64 32, i32 66, ptr @20), !dbg !167
  store i32 %39, ptr %11, align 4, !dbg !167
  br label %20, !dbg !184, !llvm.loop !185

40:                                               ; preds = %20
  call void @__kmpc_for_static_fini(ptr @3, i32 %15), !dbg !186
  call void @__kmpc_barrier(ptr @4, i32 %15), !dbg !186
  ret void, !dbg !187
}

declare void @__kmpc_for_static_init_4(ptr, i32, i32, ptr, ptr, ptr, ptr, i32, i32)

declare i32 @MPI_Win_lock(i32 noundef, i32 noundef, i32 noundef, ptr noundef) #2

declare i32 @MPI_Put(ptr noundef, i32 noundef, ptr noundef, i32 noundef, i64 noundef, i32 noundef, ptr noundef, ptr noundef) #2

declare i32 @MPI_Win_unlock(i32 noundef, ptr noundef) #2

declare i32 @sleep(i32 noundef) #2

; Function Attrs: nounwind
declare void @__kmpc_for_static_fini(ptr, i32) #4

; Function Attrs: convergent nounwind
declare void @__kmpc_barrier(ptr, i32) #5

; Function Attrs: noinline norecurse nounwind optnone uwtable
define internal void @.omp_outlined.(ptr noalias noundef %0, ptr noalias noundef %1, ptr noundef nonnull align 8 dereferenceable(8) %2) #3 !dbg !188 {
  %4 = alloca ptr, align 8
  %5 = alloca ptr, align 8
  %6 = alloca ptr, align 8
  store ptr %0, ptr %4, align 8
  call void @llvm.dbg.declare(metadata ptr %4, metadata !189, metadata !DIExpression()), !dbg !190
  store ptr %1, ptr %5, align 8
  call void @llvm.dbg.declare(metadata ptr %5, metadata !191, metadata !DIExpression()), !dbg !190
  store ptr %2, ptr %6, align 8
  call void @llvm.dbg.declare(metadata ptr %6, metadata !192, metadata !DIExpression()), !dbg !190
  %7 = load ptr, ptr %6, align 8, !dbg !193
  %8 = load ptr, ptr %4, align 8, !dbg !193
  %9 = load ptr, ptr %5, align 8, !dbg !193
  %10 = load ptr, ptr %6, align 8, !dbg !193
  call void @.omp_outlined._debug__(ptr %8, ptr %9, ptr %10) #4, !dbg !193
  ret void, !dbg !193
}

; Function Attrs: nounwind
declare i32 @__kmpc_global_thread_num(ptr) #4

; Function Attrs: nounwind
declare void @__kmpc_push_num_threads(ptr, i32, i32) #4

; Function Attrs: nounwind
declare !callback !194 void @__kmpc_fork_call(ptr, i32, ptr, ...) #4

declare i32 @MPI_Win_free(ptr noundef) #2

declare i32 @MPI_Finalize() #2

declare i32 @parcoach_rma_MPI_Win_allocate(i64, i32, ptr, ptr, ptr, ptr, i32, ptr)

declare i32 @parcoach_rma_MPI_Barrier(ptr, i32, ptr)

declare i32 @parcoach_rma_MPI_Win_free(ptr, i32, ptr)

declare i32 @parcoach_rma_MPI_Win_lock(i32, i32, i32, ptr, i32, ptr)

declare void @parcoach_rma_load(ptr, i64, i32, ptr)

declare i32 @parcoach_rma_MPI_Put(ptr, i32, ptr, i32, i64, i32, ptr, ptr, i32, ptr)

declare i32 @parcoach_rma_MPI_Win_unlock(i32, ptr, i32, ptr)

declare void @parcoach_rma_store(ptr, i64, i32, ptr)

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nocallback nofree nosync nounwind readnone speculatable willreturn }
attributes #2 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #3 = { noinline norecurse nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #4 = { nounwind }
attributes #5 = { convergent nounwind }

!llvm.dbg.cu = !{!22}
!llvm.module.flags = !{!44, !45, !46, !47, !48, !49, !50, !51}
!llvm.ident = !{!52}

!0 = !DIGlobalVariableExpression(var: !1, expr: !DIExpression())
!1 = distinct !DIGlobalVariable(scope: null, file: !2, line: 46, type: !3, isLocal: true, isDefinition: true)
!2 = !DIFile(filename: "results-20240330-164421/PARCOACH-dynamic/hybrid/021-MPI-hybrid-section-barrier-origin-remote-yes.c", directory: "/rmaracebench", checksumkind: CSK_MD5, checksum: "c9ae8590d6952cf2485eb6c5acd73d1c")
!3 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 280, elements: !5)
!4 = !DIBasicType(name: "char", size: 8, encoding: DW_ATE_signed_char)
!5 = !{!6}
!6 = !DISubrange(count: 35)
!7 = !DIGlobalVariableExpression(var: !8, expr: !DIExpression())
!8 = distinct !DIGlobalVariable(scope: null, file: !2, line: 53, type: !9, isLocal: true, isDefinition: true)
!9 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 392, elements: !10)
!10 = !{!11}
!11 = !DISubrange(count: 49)
!12 = !DIGlobalVariableExpression(var: !13, expr: !DIExpression())
!13 = distinct !DIGlobalVariable(scope: null, file: !2, line: 89, type: !14, isLocal: true, isDefinition: true)
!14 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 152, elements: !15)
!15 = !{!16}
!16 = !DISubrange(count: 19)
!17 = !DIGlobalVariableExpression(var: !18, expr: !DIExpression())
!18 = distinct !DIGlobalVariable(scope: null, file: !2, line: 94, type: !19, isLocal: true, isDefinition: true)
!19 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 752, elements: !20)
!20 = !{!21}
!21 = !DISubrange(count: 94)
!22 = distinct !DICompileUnit(language: DW_LANG_C99, file: !2, producer: "Debian clang version 15.0.6", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, enums: !23, retainedTypes: !32, globals: !43, splitDebugInlining: false, nameTableKind: None)
!23 = !{!24}
!24 = !DICompositeType(tag: DW_TAG_enumeration_type, file: !25, line: 708, baseType: !26, size: 32, elements: !27)
!25 = !DIFile(filename: "/usr/lib/x86_64-linux-gnu/openmpi/include/mpi.h", directory: "", checksumkind: CSK_MD5, checksum: "c3ca5be6f2c6a6e16d01846df47c0b49")
!26 = !DIBasicType(name: "unsigned int", size: 32, encoding: DW_ATE_unsigned)
!27 = !{!28, !29, !30, !31}
!28 = !DIEnumerator(name: "MPI_THREAD_SINGLE", value: 0)
!29 = !DIEnumerator(name: "MPI_THREAD_FUNNELED", value: 1)
!30 = !DIEnumerator(name: "MPI_THREAD_SERIALIZED", value: 2)
!31 = !DIEnumerator(name: "MPI_THREAD_MULTIPLE", value: 3)
!32 = !{!33, !36, !37, !40}
!33 = !DIDerivedType(tag: DW_TAG_typedef, name: "MPI_Comm", file: !25, line: 419, baseType: !34)
!34 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !35, size: 64)
!35 = !DICompositeType(tag: DW_TAG_structure_type, name: "ompi_communicator_t", file: !25, line: 419, flags: DIFlagFwdDecl)
!36 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: null, size: 64)
!37 = !DIDerivedType(tag: DW_TAG_typedef, name: "MPI_Info", file: !25, line: 424, baseType: !38)
!38 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !39, size: 64)
!39 = !DICompositeType(tag: DW_TAG_structure_type, name: "ompi_info_t", file: !25, line: 424, flags: DIFlagFwdDecl)
!40 = !DIDerivedType(tag: DW_TAG_typedef, name: "MPI_Datatype", file: !25, line: 420, baseType: !41)
!41 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !42, size: 64)
!42 = !DICompositeType(tag: DW_TAG_structure_type, name: "ompi_datatype_t", file: !25, line: 420, flags: DIFlagFwdDecl)
!43 = !{!0, !7, !12, !17}
!44 = !{i32 7, !"Dwarf Version", i32 5}
!45 = !{i32 2, !"Debug Info Version", i32 3}
!46 = !{i32 1, !"wchar_size", i32 4}
!47 = !{i32 7, !"openmp", i32 50}
!48 = !{i32 7, !"PIC Level", i32 2}
!49 = !{i32 7, !"PIE Level", i32 2}
!50 = !{i32 7, !"uwtable", i32 2}
!51 = !{i32 7, !"frame-pointer", i32 2}
!52 = !{!"Debian clang version 15.0.6"}
!53 = distinct !DISubprogram(name: "main", scope: !2, file: !2, line: 34, type: !54, scopeLine: 35, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !22, retainedNodes: !59)
!54 = !DISubroutineType(types: !55)
!55 = !{!56, !56, !57}
!56 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!57 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !58, size: 64)
!58 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !4, size: 64)
!59 = !{}
!60 = !DILocalVariable(name: "argc", arg: 1, scope: !53, file: !2, line: 34, type: !56)
!61 = !DILocation(line: 34, column: 14, scope: !53)
!62 = !DILocalVariable(name: "argv", arg: 2, scope: !53, file: !2, line: 34, type: !57)
!63 = !DILocation(line: 34, column: 27, scope: !53)
!64 = !DILocalVariable(name: "rank", scope: !53, file: !2, line: 36, type: !56)
!65 = !DILocation(line: 36, column: 9, scope: !53)
!66 = !DILocalVariable(name: "size", scope: !53, file: !2, line: 36, type: !56)
!67 = !DILocation(line: 36, column: 15, scope: !53)
!68 = !DILocalVariable(name: "win", scope: !53, file: !2, line: 37, type: !69)
!69 = !DIDerivedType(tag: DW_TAG_typedef, name: "MPI_Win", file: !25, line: 429, baseType: !70)
!70 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !71, size: 64)
!71 = !DICompositeType(tag: DW_TAG_structure_type, name: "ompi_win_t", file: !25, line: 429, flags: DIFlagFwdDecl)
!72 = !DILocation(line: 37, column: 13, scope: !53)
!73 = !DILocalVariable(name: "win_base", scope: !53, file: !2, line: 38, type: !74)
!74 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !56, size: 64)
!75 = !DILocation(line: 38, column: 10, scope: !53)
!76 = !DILocalVariable(name: "value", scope: !53, file: !2, line: 39, type: !56)
!77 = !DILocation(line: 39, column: 9, scope: !53)
!78 = !DILocalVariable(name: "value2", scope: !53, file: !2, line: 39, type: !56)
!79 = !DILocation(line: 39, column: 20, scope: !53)
!80 = !DILocalVariable(name: "result", scope: !53, file: !2, line: 40, type: !56)
!81 = !DILocation(line: 40, column: 9, scope: !53)
!82 = !DILocalVariable(name: "token", scope: !53, file: !2, line: 41, type: !56)
!83 = !DILocation(line: 41, column: 9, scope: !53)
!84 = !DILocalVariable(name: "provided", scope: !53, file: !2, line: 43, type: !56)
!85 = !DILocation(line: 43, column: 9, scope: !53)
!86 = !DILocation(line: 44, column: 5, scope: !53)
!87 = !DILocation(line: 45, column: 9, scope: !88)
!88 = distinct !DILexicalBlock(scope: !53, file: !2, line: 45, column: 9)
!89 = !DILocation(line: 45, column: 18, scope: !88)
!90 = !DILocation(line: 45, column: 9, scope: !53)
!91 = !DILocation(line: 46, column: 9, scope: !92)
!92 = distinct !DILexicalBlock(scope: !88, file: !2, line: 45, column: 41)
!93 = !DILocation(line: 47, column: 9, scope: !92)
!94 = !DILocation(line: 48, column: 5, scope: !92)
!95 = !DILocation(line: 49, column: 5, scope: !53)
!96 = !DILocation(line: 50, column: 5, scope: !53)
!97 = !DILocation(line: 52, column: 9, scope: !98)
!98 = distinct !DILexicalBlock(scope: !53, file: !2, line: 52, column: 9)
!99 = !DILocation(line: 52, column: 14, scope: !98)
!100 = !DILocation(line: 52, column: 9, scope: !53)
!101 = !DILocation(line: 53, column: 69, scope: !102)
!102 = distinct !DILexicalBlock(scope: !98, file: !2, line: 52, column: 27)
!103 = !DILocation(line: 53, column: 9, scope: !102)
!104 = !DILocation(line: 54, column: 9, scope: !102)
!105 = !DILocation(line: 55, column: 5, scope: !102)
!106 = !DILocation(line: 57, column: 5, scope: !53)
!107 = !DILocalVariable(name: "i", scope: !108, file: !2, line: 58, type: !56)
!108 = distinct !DILexicalBlock(scope: !53, file: !2, line: 58, column: 5)
!109 = !DILocation(line: 58, column: 14, scope: !108)
!110 = !DILocation(line: 58, column: 10, scope: !108)
!111 = !DILocation(line: 58, column: 21, scope: !112)
!112 = distinct !DILexicalBlock(scope: !108, file: !2, line: 58, column: 5)
!113 = !DILocation(line: 58, column: 23, scope: !112)
!114 = !DILocation(line: 58, column: 5, scope: !108)
!115 = !DILocation(line: 59, column: 9, scope: !116)
!116 = distinct !DILexicalBlock(scope: !112, file: !2, line: 58, column: 40)
!117 = !DILocation(line: 59, column: 18, scope: !116)
!118 = !DILocation(line: 59, column: 21, scope: !116)
!119 = !DILocation(line: 60, column: 5, scope: !116)
!120 = !DILocation(line: 58, column: 36, scope: !112)
!121 = !DILocation(line: 58, column: 5, scope: !112)
!122 = distinct !{!122, !114, !123, !124}
!123 = !DILocation(line: 60, column: 5, scope: !108)
!124 = !{!"llvm.loop.mustprogress"}
!125 = !DILocation(line: 61, column: 5, scope: !53)
!126 = !DILocation(line: 63, column: 9, scope: !127)
!127 = distinct !DILexicalBlock(scope: !53, file: !2, line: 63, column: 9)
!128 = !DILocation(line: 63, column: 14, scope: !127)
!129 = !DILocation(line: 63, column: 9, scope: !53)
!130 = !DILocation(line: 64, column: 1, scope: !131)
!131 = distinct !DILexicalBlock(scope: !127, file: !2, line: 63, column: 20)
!132 = !DILocation(line: 84, column: 5, scope: !131)
!133 = !DILocation(line: 86, column: 9, scope: !134)
!134 = distinct !DILexicalBlock(scope: !53, file: !2, line: 86, column: 9)
!135 = !DILocation(line: 86, column: 14, scope: !134)
!136 = !DILocation(line: 86, column: 9, scope: !53)
!137 = !DILocation(line: 87, column: 9, scope: !138)
!138 = distinct !DILexicalBlock(scope: !134, file: !2, line: 86, column: 20)
!139 = !DILocation(line: 89, column: 39, scope: !138)
!140 = !DILocation(line: 89, column: 9, scope: !138)
!141 = !DILocation(line: 90, column: 5, scope: !138)
!142 = !DILocation(line: 92, column: 5, scope: !53)
!143 = !DILocation(line: 95, column: 9, scope: !53)
!144 = !DILocation(line: 96, column: 9, scope: !53)
!145 = !DILocation(line: 97, column: 9, scope: !53)
!146 = !DILocation(line: 98, column: 9, scope: !53)
!147 = !DILocation(line: 93, column: 5, scope: !53)
!148 = !DILocation(line: 100, column: 5, scope: !53)
!149 = !DILocation(line: 101, column: 5, scope: !53)
!150 = !DILocation(line: 103, column: 5, scope: !53)
!151 = distinct !DISubprogram(name: ".omp_outlined._debug__", scope: !2, file: !2, line: 65, type: !152, scopeLine: 65, flags: DIFlagPrototyped, spFlags: DISPFlagLocalToUnit | DISPFlagDefinition, unit: !22, retainedNodes: !59)
!152 = !DISubroutineType(types: !153)
!153 = !{null, !154, !154, !158}
!154 = !DIDerivedType(tag: DW_TAG_const_type, baseType: !155)
!155 = !DIDerivedType(tag: DW_TAG_restrict_type, baseType: !156)
!156 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !157, size: 64)
!157 = !DIDerivedType(tag: DW_TAG_const_type, baseType: !56)
!158 = !DIDerivedType(tag: DW_TAG_reference_type, baseType: !69, size: 64)
!159 = !DILocalVariable(name: ".global_tid.", arg: 1, scope: !151, type: !154, flags: DIFlagArtificial)
!160 = !DILocation(line: 0, scope: !151)
!161 = !DILocalVariable(name: ".bound_tid.", arg: 2, scope: !151, type: !154, flags: DIFlagArtificial)
!162 = !DILocalVariable(name: "win", arg: 3, scope: !151, file: !2, line: 37, type: !158)
!163 = !DILocation(line: 37, column: 13, scope: !151)
!164 = !DILocation(line: 65, column: 9, scope: !151)
!165 = !DILocation(line: 66, column: 1, scope: !166)
!166 = distinct !DILexicalBlock(scope: !151, file: !2, line: 65, column: 9)
!167 = !DILocation(line: 66, column: 1, scope: !168)
!168 = distinct !DILexicalBlock(scope: !166, file: !2, line: 66, column: 1)
!169 = !DILocalVariable(name: "value", scope: !170, file: !2, line: 70, type: !56)
!170 = distinct !DILexicalBlock(scope: !171, file: !2, line: 69, column: 17)
!171 = distinct !DILexicalBlock(scope: !168, file: !2, line: 68, column: 1)
!172 = !DILocation(line: 70, column: 25, scope: !170)
!173 = !DILocation(line: 71, column: 60, scope: !170)
!174 = !DILocation(line: 71, column: 21, scope: !170)
!175 = !DILocation(line: 73, column: 67, scope: !170)
!176 = !DILocation(line: 73, column: 21, scope: !170)
!177 = !DILocation(line: 74, column: 39, scope: !170)
!178 = !DILocation(line: 74, column: 21, scope: !170)
!179 = !DILocation(line: 68, column: 20, scope: !171)
!180 = !DILocation(line: 79, column: 21, scope: !181)
!181 = distinct !DILexicalBlock(scope: !182, file: !2, line: 78, column: 17)
!182 = distinct !DILexicalBlock(scope: !168, file: !2, line: 77, column: 1)
!183 = !DILocation(line: 80, column: 21, scope: !181)
!184 = !DILocation(line: 77, column: 20, scope: !182)
!185 = distinct !{!185, !167, !186}
!186 = !DILocation(line: 66, column: 21, scope: !168)
!187 = !DILocation(line: 83, column: 9, scope: !151)
!188 = distinct !DISubprogram(name: ".omp_outlined.", scope: !2, file: !2, line: 64, type: !152, scopeLine: 64, flags: DIFlagPrototyped, spFlags: DISPFlagLocalToUnit | DISPFlagDefinition, unit: !22, retainedNodes: !59)
!189 = !DILocalVariable(name: ".global_tid.", arg: 1, scope: !188, type: !154, flags: DIFlagArtificial)
!190 = !DILocation(line: 0, scope: !188)
!191 = !DILocalVariable(name: ".bound_tid.", arg: 2, scope: !188, type: !154, flags: DIFlagArtificial)
!192 = !DILocalVariable(name: "win", arg: 3, scope: !188, type: !158, flags: DIFlagArtificial)
!193 = !DILocation(line: 64, column: 1, scope: !188)
!194 = !{!195}
!195 = !{i64 2, i64 -1, i64 -1, i1 true}
