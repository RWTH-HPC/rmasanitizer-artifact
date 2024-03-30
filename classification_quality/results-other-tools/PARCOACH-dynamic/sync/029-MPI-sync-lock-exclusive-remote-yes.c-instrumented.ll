; ModuleID = 'results-20240330-164421/PARCOACH-dynamic/sync/029-MPI-sync-lock-exclusive-remote-yes.c.ll'
source_filename = "results-20240330-164421/PARCOACH-dynamic/sync/029-MPI-sync-lock-exclusive-remote-yes.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct.ompi_predefined_communicator_t = type opaque
%struct.ompi_predefined_info_t = type opaque
%struct.ompi_predefined_datatype_t = type opaque

@ompi_mpi_comm_world = external global %struct.ompi_predefined_communicator_t, align 1
@.str = private unnamed_addr constant [49 x i8] c"Wrong number of MPI processes: %d. Expected: %d\0A\00", align 1, !dbg !0
@ompi_mpi_info_null = external global %struct.ompi_predefined_info_t, align 1
@ompi_mpi_int = external global %struct.ompi_predefined_datatype_t, align 1
@.str.1 = private unnamed_addr constant [19 x i8] c"win_base[0] is %d\0A\00", align 1, !dbg !7
@.str.2 = private unnamed_addr constant [94 x i8] c"Process %d: Execution finished, variable contents: value = %d, value2 = %d, win_base[0] = %d\0A\00", align 1, !dbg !12
@0 = private unnamed_addr constant [87 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/029-MPI-sync-lock-exclusive-remote-yes.c\00", align 1
@1 = private unnamed_addr constant [87 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/029-MPI-sync-lock-exclusive-remote-yes.c\00", align 1
@2 = private unnamed_addr constant [87 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/029-MPI-sync-lock-exclusive-remote-yes.c\00", align 1
@3 = private unnamed_addr constant [87 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/029-MPI-sync-lock-exclusive-remote-yes.c\00", align 1
@4 = private unnamed_addr constant [87 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/029-MPI-sync-lock-exclusive-remote-yes.c\00", align 1
@5 = private unnamed_addr constant [87 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/029-MPI-sync-lock-exclusive-remote-yes.c\00", align 1
@6 = private unnamed_addr constant [87 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/029-MPI-sync-lock-exclusive-remote-yes.c\00", align 1
@7 = private unnamed_addr constant [87 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/029-MPI-sync-lock-exclusive-remote-yes.c\00", align 1
@8 = private unnamed_addr constant [87 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/029-MPI-sync-lock-exclusive-remote-yes.c\00", align 1
@9 = private unnamed_addr constant [87 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/029-MPI-sync-lock-exclusive-remote-yes.c\00", align 1
@10 = private unnamed_addr constant [87 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/029-MPI-sync-lock-exclusive-remote-yes.c\00", align 1
@11 = private unnamed_addr constant [87 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/029-MPI-sync-lock-exclusive-remote-yes.c\00", align 1
@12 = private unnamed_addr constant [87 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/029-MPI-sync-lock-exclusive-remote-yes.c\00", align 1
@13 = private unnamed_addr constant [87 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/029-MPI-sync-lock-exclusive-remote-yes.c\00", align 1
@14 = private unnamed_addr constant [87 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/029-MPI-sync-lock-exclusive-remote-yes.c\00", align 1
@15 = private unnamed_addr constant [87 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/029-MPI-sync-lock-exclusive-remote-yes.c\00", align 1
@16 = private unnamed_addr constant [87 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/029-MPI-sync-lock-exclusive-remote-yes.c\00", align 1
@17 = private unnamed_addr constant [87 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/029-MPI-sync-lock-exclusive-remote-yes.c\00", align 1
@18 = private unnamed_addr constant [87 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/029-MPI-sync-lock-exclusive-remote-yes.c\00", align 1
@19 = private unnamed_addr constant [87 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/029-MPI-sync-lock-exclusive-remote-yes.c\00", align 1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main(i32 noundef %0, ptr noundef %1) #0 !dbg !40 {
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
  %14 = alloca ptr, align 8
  %15 = alloca ptr, align 8
  %16 = alloca i32, align 4
  store i32 0, ptr %3, align 4
  store i32 %0, ptr %4, align 4
  call void @llvm.dbg.declare(metadata ptr %4, metadata !47, metadata !DIExpression()), !dbg !48
  store ptr %1, ptr %5, align 8
  call void @llvm.dbg.declare(metadata ptr %5, metadata !49, metadata !DIExpression()), !dbg !50
  call void @llvm.dbg.declare(metadata ptr %6, metadata !51, metadata !DIExpression()), !dbg !52
  call void @llvm.dbg.declare(metadata ptr %7, metadata !53, metadata !DIExpression()), !dbg !54
  call void @llvm.dbg.declare(metadata ptr %8, metadata !55, metadata !DIExpression()), !dbg !59
  call void @llvm.dbg.declare(metadata ptr %9, metadata !60, metadata !DIExpression()), !dbg !62
  call void @llvm.dbg.declare(metadata ptr %10, metadata !63, metadata !DIExpression()), !dbg !64
  store i32 1, ptr %10, align 4, !dbg !64
  call void @llvm.dbg.declare(metadata ptr %11, metadata !65, metadata !DIExpression()), !dbg !66
  store i32 2, ptr %11, align 4, !dbg !66
  call void @llvm.dbg.declare(metadata ptr %12, metadata !67, metadata !DIExpression()), !dbg !68
  call void @llvm.dbg.declare(metadata ptr %13, metadata !69, metadata !DIExpression()), !dbg !70
  store i32 42, ptr %13, align 4, !dbg !70
  %17 = call i32 @MPI_Init(ptr noundef %4, ptr noundef %5), !dbg !71
  %18 = call i32 @MPI_Comm_rank(ptr noundef @ompi_mpi_comm_world, ptr noundef %6), !dbg !72
  %19 = call i32 @MPI_Comm_size(ptr noundef @ompi_mpi_comm_world, ptr noundef %7), !dbg !73
  %20 = load i32, ptr %7, align 4, !dbg !74
  %21 = icmp ne i32 %20, 2, !dbg !76
  br i1 %21, label %22, label %26, !dbg !77

22:                                               ; preds = %2
  %23 = load i32, ptr %7, align 4, !dbg !78
  %24 = call i32 (ptr, ...) @printf(ptr noundef @.str, i32 noundef %23, i32 noundef 2), !dbg !80
  %25 = call i32 @MPI_Abort(ptr noundef @ompi_mpi_comm_world, i32 noundef 1), !dbg !81
  br label %26, !dbg !82

26:                                               ; preds = %22, %2
  call void @llvm.dbg.declare(metadata ptr %14, metadata !83, metadata !DIExpression()), !dbg !84
  call void @llvm.dbg.declare(metadata ptr %15, metadata !85, metadata !DIExpression()), !dbg !86
  %27 = call i32 @parcoach_rma_MPI_Win_allocate(i64 40, i32 4, ptr @ompi_mpi_info_null, ptr @ompi_mpi_comm_world, ptr %9, ptr %8, i32 55, ptr @0), !dbg !87
  %28 = call i32 @parcoach_rma_MPI_Win_allocate(i64 40, i32 4, ptr @ompi_mpi_info_null, ptr @ompi_mpi_comm_world, ptr %15, ptr %14, i32 56, ptr @1), !dbg !88
  call void @llvm.dbg.declare(metadata ptr %16, metadata !89, metadata !DIExpression()), !dbg !91
  store i32 0, ptr %16, align 4, !dbg !91
  br label %29, !dbg !92

29:                                               ; preds = %41, %26
  %30 = load i32, ptr %16, align 4, !dbg !93
  %31 = icmp slt i32 %30, 10, !dbg !95
  br i1 %31, label %32, label %44, !dbg !96

32:                                               ; preds = %29
  %33 = load ptr, ptr %9, align 8, !dbg !97
  %34 = load i32, ptr %16, align 4, !dbg !99
  %35 = sext i32 %34 to i64, !dbg !97
  %36 = getelementptr inbounds i32, ptr %33, i64 %35, !dbg !97
  store i32 0, ptr %36, align 4, !dbg !100
  %37 = load ptr, ptr %15, align 8, !dbg !101
  %38 = load i32, ptr %16, align 4, !dbg !102
  %39 = sext i32 %38 to i64, !dbg !101
  %40 = getelementptr inbounds i32, ptr %37, i64 %39, !dbg !101
  store i32 0, ptr %40, align 4, !dbg !103
  br label %41, !dbg !104

41:                                               ; preds = %32
  %42 = load i32, ptr %16, align 4, !dbg !105
  %43 = add nsw i32 %42, 1, !dbg !105
  store i32 %43, ptr %16, align 4, !dbg !105
  br label %29, !dbg !106, !llvm.loop !107

44:                                               ; preds = %29
  %45 = call i32 @parcoach_rma_MPI_Barrier(ptr @ompi_mpi_comm_world, i32 63, ptr @2), !dbg !110
  %46 = load i32, ptr %6, align 4, !dbg !111
  %47 = icmp eq i32 %46, 0, !dbg !113
  br i1 %47, label %48, label %60, !dbg !114

48:                                               ; preds = %44
  %49 = load ptr, ptr %8, align 8, !dbg !115
  %50 = call i32 @parcoach_rma_MPI_Win_lock(i32 1, i32 1, i32 0, ptr %49, i32 66, ptr @3), !dbg !117
  call void @parcoach_rma_load(ptr %8, i64 64, i32 68, ptr @4), !dbg !118
  %51 = load ptr, ptr %8, align 8, !dbg !118
  %52 = call i32 @parcoach_rma_MPI_Put(ptr %10, i32 1, ptr @ompi_mpi_int, i32 1, i64 0, i32 1, ptr @ompi_mpi_int, ptr %51, i32 68, ptr @5), !dbg !119
  %53 = load ptr, ptr %8, align 8, !dbg !120
  %54 = call i32 @parcoach_rma_MPI_Win_unlock(i32 1, ptr %53, i32 69, ptr @6), !dbg !121
  %55 = call i32 @sleep(i32 noundef 1), !dbg !122
  call void @parcoach_rma_load(ptr %14, i64 64, i32 74, ptr @7), !dbg !123
  %56 = load ptr, ptr %14, align 8, !dbg !123
  %57 = call i32 @parcoach_rma_MPI_Win_lock(i32 1, i32 1, i32 0, ptr %56, i32 74, ptr @8), !dbg !124
  call void @parcoach_rma_load(ptr %14, i64 64, i32 75, ptr @9), !dbg !125
  %58 = load ptr, ptr %14, align 8, !dbg !125
  %59 = call i32 @parcoach_rma_MPI_Win_unlock(i32 1, ptr %58, i32 75, ptr @10), !dbg !126
  br label %69, !dbg !127

60:                                               ; preds = %44
  call void @parcoach_rma_load(ptr %14, i64 64, i32 78, ptr @11), !dbg !128
  %61 = load ptr, ptr %14, align 8, !dbg !128
  %62 = call i32 @parcoach_rma_MPI_Win_lock(i32 1, i32 1, i32 0, ptr %61, i32 78, ptr @12), !dbg !130
  call void @parcoach_rma_load(ptr %14, i64 64, i32 79, ptr @13), !dbg !131
  %63 = load ptr, ptr %14, align 8, !dbg !131
  %64 = call i32 @parcoach_rma_MPI_Win_unlock(i32 1, ptr %63, i32 79, ptr @14), !dbg !132
  call void @parcoach_rma_load(ptr %9, i64 64, i32 81, ptr @15), !dbg !133
  %65 = load ptr, ptr %9, align 8, !dbg !133
  %66 = getelementptr inbounds i32, ptr %65, i64 0, !dbg !133
  call void @parcoach_rma_load(ptr %66, i64 32, i32 81, ptr @16), !dbg !133
  %67 = load i32, ptr %66, align 4, !dbg !133
  %68 = call i32 (ptr, ...) @printf(ptr noundef @.str.1, i32 noundef %67), !dbg !134
  br label %69

69:                                               ; preds = %60, %48
  %70 = call i32 @parcoach_rma_MPI_Win_free(ptr %14, i32 84, ptr @17), !dbg !135
  %71 = call i32 @parcoach_rma_MPI_Barrier(ptr @ompi_mpi_comm_world, i32 86, ptr @18), !dbg !136
  %72 = load i32, ptr %6, align 4, !dbg !137
  %73 = load i32, ptr %10, align 4, !dbg !138
  %74 = load i32, ptr %11, align 4, !dbg !139
  %75 = load ptr, ptr %9, align 8, !dbg !140
  %76 = getelementptr inbounds i32, ptr %75, i64 0, !dbg !140
  %77 = load i32, ptr %76, align 4, !dbg !140
  %78 = call i32 (ptr, ...) @printf(ptr noundef @.str.2, i32 noundef %72, i32 noundef %73, i32 noundef %74, i32 noundef %77), !dbg !141
  %79 = call i32 @parcoach_rma_MPI_Win_free(ptr %8, i32 94, ptr @19), !dbg !142
  %80 = call i32 @MPI_Finalize(), !dbg !143
  ret i32 0, !dbg !144
}

; Function Attrs: nocallback nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

declare i32 @MPI_Init(ptr noundef, ptr noundef) #2

declare i32 @MPI_Comm_rank(ptr noundef, ptr noundef) #2

declare i32 @MPI_Comm_size(ptr noundef, ptr noundef) #2

declare i32 @printf(ptr noundef, ...) #2

declare i32 @MPI_Abort(ptr noundef, i32 noundef) #2

declare i32 @MPI_Win_allocate(i64 noundef, i32 noundef, ptr noundef, ptr noundef, ptr noundef, ptr noundef) #2

declare i32 @MPI_Barrier(ptr noundef) #2

declare i32 @MPI_Win_lock(i32 noundef, i32 noundef, i32 noundef, ptr noundef) #2

declare i32 @MPI_Put(ptr noundef, i32 noundef, ptr noundef, i32 noundef, i64 noundef, i32 noundef, ptr noundef, ptr noundef) #2

declare i32 @MPI_Win_unlock(i32 noundef, ptr noundef) #2

declare i32 @sleep(i32 noundef) #2

declare i32 @MPI_Win_free(ptr noundef) #2

declare i32 @MPI_Finalize() #2

declare i32 @parcoach_rma_MPI_Win_allocate(i64, i32, ptr, ptr, ptr, ptr, i32, ptr)

declare i32 @parcoach_rma_MPI_Barrier(ptr, i32, ptr)

declare i32 @parcoach_rma_MPI_Win_lock(i32, i32, i32, ptr, i32, ptr)

declare void @parcoach_rma_load(ptr, i64, i32, ptr)

declare i32 @parcoach_rma_MPI_Put(ptr, i32, ptr, i32, i64, i32, ptr, ptr, i32, ptr)

declare i32 @parcoach_rma_MPI_Win_unlock(i32, ptr, i32, ptr)

declare i32 @parcoach_rma_MPI_Win_free(ptr, i32, ptr)

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nocallback nofree nosync nounwind readnone speculatable willreturn }
attributes #2 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.dbg.cu = !{!17}
!llvm.module.flags = !{!31, !32, !33, !34, !35, !36, !37, !38}
!llvm.ident = !{!39}

!0 = !DIGlobalVariableExpression(var: !1, expr: !DIExpression())
!1 = distinct !DIGlobalVariable(scope: null, file: !2, line: 48, type: !3, isLocal: true, isDefinition: true)
!2 = !DIFile(filename: "results-20240330-164421/PARCOACH-dynamic/sync/029-MPI-sync-lock-exclusive-remote-yes.c", directory: "/rmaracebench", checksumkind: CSK_MD5, checksum: "6e7d332f56331db9a03f436bf211f8f1")
!3 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 392, elements: !5)
!4 = !DIBasicType(name: "char", size: 8, encoding: DW_ATE_signed_char)
!5 = !{!6}
!6 = !DISubrange(count: 49)
!7 = !DIGlobalVariableExpression(var: !8, expr: !DIExpression())
!8 = distinct !DIGlobalVariable(scope: null, file: !2, line: 81, type: !9, isLocal: true, isDefinition: true)
!9 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 152, elements: !10)
!10 = !{!11}
!11 = !DISubrange(count: 19)
!12 = !DIGlobalVariableExpression(var: !13, expr: !DIExpression())
!13 = distinct !DIGlobalVariable(scope: null, file: !2, line: 88, type: !14, isLocal: true, isDefinition: true)
!14 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 752, elements: !15)
!15 = !{!16}
!16 = !DISubrange(count: 94)
!17 = distinct !DICompileUnit(language: DW_LANG_C99, file: !2, producer: "Debian clang version 15.0.6", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, retainedTypes: !18, globals: !30, splitDebugInlining: false, nameTableKind: None)
!18 = !{!19, !23, !24, !27}
!19 = !DIDerivedType(tag: DW_TAG_typedef, name: "MPI_Comm", file: !20, line: 419, baseType: !21)
!20 = !DIFile(filename: "/usr/lib/x86_64-linux-gnu/openmpi/include/mpi.h", directory: "", checksumkind: CSK_MD5, checksum: "c3ca5be6f2c6a6e16d01846df47c0b49")
!21 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !22, size: 64)
!22 = !DICompositeType(tag: DW_TAG_structure_type, name: "ompi_communicator_t", file: !20, line: 419, flags: DIFlagFwdDecl)
!23 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: null, size: 64)
!24 = !DIDerivedType(tag: DW_TAG_typedef, name: "MPI_Info", file: !20, line: 424, baseType: !25)
!25 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !26, size: 64)
!26 = !DICompositeType(tag: DW_TAG_structure_type, name: "ompi_info_t", file: !20, line: 424, flags: DIFlagFwdDecl)
!27 = !DIDerivedType(tag: DW_TAG_typedef, name: "MPI_Datatype", file: !20, line: 420, baseType: !28)
!28 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !29, size: 64)
!29 = !DICompositeType(tag: DW_TAG_structure_type, name: "ompi_datatype_t", file: !20, line: 420, flags: DIFlagFwdDecl)
!30 = !{!0, !7, !12}
!31 = !{i32 7, !"Dwarf Version", i32 5}
!32 = !{i32 2, !"Debug Info Version", i32 3}
!33 = !{i32 1, !"wchar_size", i32 4}
!34 = !{i32 7, !"openmp", i32 50}
!35 = !{i32 7, !"PIC Level", i32 2}
!36 = !{i32 7, !"PIE Level", i32 2}
!37 = !{i32 7, !"uwtable", i32 2}
!38 = !{i32 7, !"frame-pointer", i32 2}
!39 = !{!"Debian clang version 15.0.6"}
!40 = distinct !DISubprogram(name: "main", scope: !2, file: !2, line: 34, type: !41, scopeLine: 35, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !17, retainedNodes: !46)
!41 = !DISubroutineType(types: !42)
!42 = !{!43, !43, !44}
!43 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!44 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !45, size: 64)
!45 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !4, size: 64)
!46 = !{}
!47 = !DILocalVariable(name: "argc", arg: 1, scope: !40, file: !2, line: 34, type: !43)
!48 = !DILocation(line: 34, column: 14, scope: !40)
!49 = !DILocalVariable(name: "argv", arg: 2, scope: !40, file: !2, line: 34, type: !44)
!50 = !DILocation(line: 34, column: 27, scope: !40)
!51 = !DILocalVariable(name: "rank", scope: !40, file: !2, line: 36, type: !43)
!52 = !DILocation(line: 36, column: 9, scope: !40)
!53 = !DILocalVariable(name: "size", scope: !40, file: !2, line: 36, type: !43)
!54 = !DILocation(line: 36, column: 15, scope: !40)
!55 = !DILocalVariable(name: "win", scope: !40, file: !2, line: 37, type: !56)
!56 = !DIDerivedType(tag: DW_TAG_typedef, name: "MPI_Win", file: !20, line: 429, baseType: !57)
!57 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !58, size: 64)
!58 = !DICompositeType(tag: DW_TAG_structure_type, name: "ompi_win_t", file: !20, line: 429, flags: DIFlagFwdDecl)
!59 = !DILocation(line: 37, column: 13, scope: !40)
!60 = !DILocalVariable(name: "win_base", scope: !40, file: !2, line: 38, type: !61)
!61 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !43, size: 64)
!62 = !DILocation(line: 38, column: 10, scope: !40)
!63 = !DILocalVariable(name: "value", scope: !40, file: !2, line: 39, type: !43)
!64 = !DILocation(line: 39, column: 9, scope: !40)
!65 = !DILocalVariable(name: "value2", scope: !40, file: !2, line: 39, type: !43)
!66 = !DILocation(line: 39, column: 20, scope: !40)
!67 = !DILocalVariable(name: "result", scope: !40, file: !2, line: 40, type: !43)
!68 = !DILocation(line: 40, column: 9, scope: !40)
!69 = !DILocalVariable(name: "token", scope: !40, file: !2, line: 41, type: !43)
!70 = !DILocation(line: 41, column: 9, scope: !40)
!71 = !DILocation(line: 43, column: 5, scope: !40)
!72 = !DILocation(line: 44, column: 5, scope: !40)
!73 = !DILocation(line: 45, column: 5, scope: !40)
!74 = !DILocation(line: 47, column: 9, scope: !75)
!75 = distinct !DILexicalBlock(scope: !40, file: !2, line: 47, column: 9)
!76 = !DILocation(line: 47, column: 14, scope: !75)
!77 = !DILocation(line: 47, column: 9, scope: !40)
!78 = !DILocation(line: 48, column: 69, scope: !79)
!79 = distinct !DILexicalBlock(scope: !75, file: !2, line: 47, column: 27)
!80 = !DILocation(line: 48, column: 9, scope: !79)
!81 = !DILocation(line: 49, column: 9, scope: !79)
!82 = !DILocation(line: 50, column: 5, scope: !79)
!83 = !DILocalVariable(name: "win2", scope: !40, file: !2, line: 52, type: !56)
!84 = !DILocation(line: 52, column: 13, scope: !40)
!85 = !DILocalVariable(name: "win_base2", scope: !40, file: !2, line: 53, type: !61)
!86 = !DILocation(line: 53, column: 10, scope: !40)
!87 = !DILocation(line: 55, column: 5, scope: !40)
!88 = !DILocation(line: 56, column: 5, scope: !40)
!89 = !DILocalVariable(name: "i", scope: !90, file: !2, line: 58, type: !43)
!90 = distinct !DILexicalBlock(scope: !40, file: !2, line: 58, column: 5)
!91 = !DILocation(line: 58, column: 14, scope: !90)
!92 = !DILocation(line: 58, column: 10, scope: !90)
!93 = !DILocation(line: 58, column: 21, scope: !94)
!94 = distinct !DILexicalBlock(scope: !90, file: !2, line: 58, column: 5)
!95 = !DILocation(line: 58, column: 23, scope: !94)
!96 = !DILocation(line: 58, column: 5, scope: !90)
!97 = !DILocation(line: 59, column: 9, scope: !98)
!98 = distinct !DILexicalBlock(scope: !94, file: !2, line: 58, column: 40)
!99 = !DILocation(line: 59, column: 18, scope: !98)
!100 = !DILocation(line: 59, column: 21, scope: !98)
!101 = !DILocation(line: 60, column: 9, scope: !98)
!102 = !DILocation(line: 60, column: 19, scope: !98)
!103 = !DILocation(line: 60, column: 22, scope: !98)
!104 = !DILocation(line: 61, column: 5, scope: !98)
!105 = !DILocation(line: 58, column: 36, scope: !94)
!106 = !DILocation(line: 58, column: 5, scope: !94)
!107 = distinct !{!107, !96, !108, !109}
!108 = !DILocation(line: 61, column: 5, scope: !90)
!109 = !{!"llvm.loop.mustprogress"}
!110 = !DILocation(line: 63, column: 5, scope: !40)
!111 = !DILocation(line: 65, column: 9, scope: !112)
!112 = distinct !DILexicalBlock(scope: !40, file: !2, line: 65, column: 9)
!113 = !DILocation(line: 65, column: 14, scope: !112)
!114 = !DILocation(line: 65, column: 9, scope: !40)
!115 = !DILocation(line: 66, column: 48, scope: !116)
!116 = distinct !DILexicalBlock(scope: !112, file: !2, line: 65, column: 20)
!117 = !DILocation(line: 66, column: 9, scope: !116)
!118 = !DILocation(line: 68, column: 55, scope: !116)
!119 = !DILocation(line: 68, column: 9, scope: !116)
!120 = !DILocation(line: 69, column: 27, scope: !116)
!121 = !DILocation(line: 69, column: 9, scope: !116)
!122 = !DILocation(line: 71, column: 9, scope: !116)
!123 = !DILocation(line: 74, column: 48, scope: !116)
!124 = !DILocation(line: 74, column: 9, scope: !116)
!125 = !DILocation(line: 75, column: 27, scope: !116)
!126 = !DILocation(line: 75, column: 9, scope: !116)
!127 = !DILocation(line: 76, column: 5, scope: !116)
!128 = !DILocation(line: 78, column: 48, scope: !129)
!129 = distinct !DILexicalBlock(scope: !112, file: !2, line: 76, column: 12)
!130 = !DILocation(line: 78, column: 9, scope: !129)
!131 = !DILocation(line: 79, column: 27, scope: !129)
!132 = !DILocation(line: 79, column: 9, scope: !129)
!133 = !DILocation(line: 81, column: 39, scope: !129)
!134 = !DILocation(line: 81, column: 9, scope: !129)
!135 = !DILocation(line: 84, column: 5, scope: !40)
!136 = !DILocation(line: 86, column: 5, scope: !40)
!137 = !DILocation(line: 89, column: 9, scope: !40)
!138 = !DILocation(line: 90, column: 9, scope: !40)
!139 = !DILocation(line: 91, column: 9, scope: !40)
!140 = !DILocation(line: 92, column: 9, scope: !40)
!141 = !DILocation(line: 87, column: 5, scope: !40)
!142 = !DILocation(line: 94, column: 5, scope: !40)
!143 = !DILocation(line: 95, column: 5, scope: !40)
!144 = !DILocation(line: 97, column: 5, scope: !40)
