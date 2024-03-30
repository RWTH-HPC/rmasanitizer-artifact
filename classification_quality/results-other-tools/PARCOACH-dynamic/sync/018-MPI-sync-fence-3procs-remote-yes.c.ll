; ModuleID = 'results-20240330-164421/PARCOACH-dynamic/sync/018-MPI-sync-fence-3procs-remote-yes.c'
source_filename = "results-20240330-164421/PARCOACH-dynamic/sync/018-MPI-sync-fence-3procs-remote-yes.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct.ompi_predefined_communicator_t = type opaque
%struct.ompi_predefined_info_t = type opaque
%struct.ompi_predefined_datatype_t = type opaque

@ompi_mpi_comm_world = external global %struct.ompi_predefined_communicator_t, align 1
@.str = private unnamed_addr constant [49 x i8] c"Wrong number of MPI processes: %d. Expected: %d\0A\00", align 1, !dbg !0
@ompi_mpi_info_null = external global %struct.ompi_predefined_info_t, align 1
@ompi_mpi_int = external global %struct.ompi_predefined_datatype_t, align 1
@.str.1 = private unnamed_addr constant [94 x i8] c"Process %d: Execution finished, variable contents: value = %d, value2 = %d, win_base[0] = %d\0A\00", align 1, !dbg !7

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main(i32 noundef %0, ptr noundef %1) #0 !dbg !35 {
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
  store i32 0, ptr %3, align 4
  store i32 %0, ptr %4, align 4
  call void @llvm.dbg.declare(metadata ptr %4, metadata !42, metadata !DIExpression()), !dbg !43
  store ptr %1, ptr %5, align 8
  call void @llvm.dbg.declare(metadata ptr %5, metadata !44, metadata !DIExpression()), !dbg !45
  call void @llvm.dbg.declare(metadata ptr %6, metadata !46, metadata !DIExpression()), !dbg !47
  call void @llvm.dbg.declare(metadata ptr %7, metadata !48, metadata !DIExpression()), !dbg !49
  call void @llvm.dbg.declare(metadata ptr %8, metadata !50, metadata !DIExpression()), !dbg !54
  call void @llvm.dbg.declare(metadata ptr %9, metadata !55, metadata !DIExpression()), !dbg !57
  call void @llvm.dbg.declare(metadata ptr %10, metadata !58, metadata !DIExpression()), !dbg !59
  store i32 1, ptr %10, align 4, !dbg !59
  call void @llvm.dbg.declare(metadata ptr %11, metadata !60, metadata !DIExpression()), !dbg !61
  store i32 2, ptr %11, align 4, !dbg !61
  call void @llvm.dbg.declare(metadata ptr %12, metadata !62, metadata !DIExpression()), !dbg !63
  call void @llvm.dbg.declare(metadata ptr %13, metadata !64, metadata !DIExpression()), !dbg !65
  store i32 42, ptr %13, align 4, !dbg !65
  %15 = call i32 @MPI_Init(ptr noundef %4, ptr noundef %5), !dbg !66
  %16 = call i32 @MPI_Comm_rank(ptr noundef @ompi_mpi_comm_world, ptr noundef %6), !dbg !67
  %17 = call i32 @MPI_Comm_size(ptr noundef @ompi_mpi_comm_world, ptr noundef %7), !dbg !68
  %18 = load i32, ptr %7, align 4, !dbg !69
  %19 = icmp ne i32 %18, 3, !dbg !71
  br i1 %19, label %20, label %24, !dbg !72

20:                                               ; preds = %2
  %21 = load i32, ptr %7, align 4, !dbg !73
  %22 = call i32 (ptr, ...) @printf(ptr noundef @.str, i32 noundef %21, i32 noundef 3), !dbg !75
  %23 = call i32 @MPI_Abort(ptr noundef @ompi_mpi_comm_world, i32 noundef 1), !dbg !76
  br label %24, !dbg !77

24:                                               ; preds = %20, %2
  %25 = call i32 @MPI_Win_allocate(i64 noundef 40, i32 noundef 4, ptr noundef @ompi_mpi_info_null, ptr noundef @ompi_mpi_comm_world, ptr noundef %9, ptr noundef %8), !dbg !78
  call void @llvm.dbg.declare(metadata ptr %14, metadata !79, metadata !DIExpression()), !dbg !81
  store i32 0, ptr %14, align 4, !dbg !81
  br label %26, !dbg !82

26:                                               ; preds = %34, %24
  %27 = load i32, ptr %14, align 4, !dbg !83
  %28 = icmp slt i32 %27, 10, !dbg !85
  br i1 %28, label %29, label %37, !dbg !86

29:                                               ; preds = %26
  %30 = load ptr, ptr %9, align 8, !dbg !87
  %31 = load i32, ptr %14, align 4, !dbg !89
  %32 = sext i32 %31 to i64, !dbg !87
  %33 = getelementptr inbounds i32, ptr %30, i64 %32, !dbg !87
  store i32 0, ptr %33, align 4, !dbg !90
  br label %34, !dbg !91

34:                                               ; preds = %29
  %35 = load i32, ptr %14, align 4, !dbg !92
  %36 = add nsw i32 %35, 1, !dbg !92
  store i32 %36, ptr %14, align 4, !dbg !92
  br label %26, !dbg !93, !llvm.loop !94

37:                                               ; preds = %26
  %38 = load ptr, ptr %8, align 8, !dbg !97
  %39 = call i32 @MPI_Win_fence(i32 noundef 0, ptr noundef %38), !dbg !98
  %40 = load i32, ptr %6, align 4, !dbg !99
  %41 = icmp eq i32 %40, 0, !dbg !101
  br i1 %41, label %42, label %45, !dbg !102

42:                                               ; preds = %37
  store i32 0, ptr %10, align 4, !dbg !103
  %43 = load ptr, ptr %8, align 8, !dbg !105
  %44 = call i32 @MPI_Put(ptr noundef %10, i32 noundef 1, ptr noundef @ompi_mpi_int, i32 noundef 1, i64 noundef 0, i32 noundef 1, ptr noundef @ompi_mpi_int, ptr noundef %43), !dbg !106
  br label %45, !dbg !107

45:                                               ; preds = %42, %37
  %46 = load i32, ptr %6, align 4, !dbg !108
  %47 = icmp eq i32 %46, 2, !dbg !110
  br i1 %47, label %48, label %51, !dbg !111

48:                                               ; preds = %45
  store i32 2, ptr %10, align 4, !dbg !112
  %49 = load ptr, ptr %8, align 8, !dbg !114
  %50 = call i32 @MPI_Get(ptr noundef %10, i32 noundef 1, ptr noundef @ompi_mpi_int, i32 noundef 1, i64 noundef 0, i32 noundef 1, ptr noundef @ompi_mpi_int, ptr noundef %49), !dbg !115
  br label %51, !dbg !116

51:                                               ; preds = %48, %45
  %52 = load ptr, ptr %8, align 8, !dbg !117
  %53 = call i32 @MPI_Win_fence(i32 noundef 0, ptr noundef %52), !dbg !118
  %54 = call i32 @MPI_Barrier(ptr noundef @ompi_mpi_comm_world), !dbg !119
  %55 = load i32, ptr %6, align 4, !dbg !120
  %56 = load i32, ptr %10, align 4, !dbg !121
  %57 = load i32, ptr %11, align 4, !dbg !122
  %58 = load ptr, ptr %9, align 8, !dbg !123
  %59 = getelementptr inbounds i32, ptr %58, i64 0, !dbg !123
  %60 = load i32, ptr %59, align 4, !dbg !123
  %61 = call i32 (ptr, ...) @printf(ptr noundef @.str.1, i32 noundef %55, i32 noundef %56, i32 noundef %57, i32 noundef %60), !dbg !124
  %62 = call i32 @MPI_Win_free(ptr noundef %8), !dbg !125
  %63 = call i32 @MPI_Finalize(), !dbg !126
  ret i32 0, !dbg !127
}

; Function Attrs: nocallback nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

declare i32 @MPI_Init(ptr noundef, ptr noundef) #2

declare i32 @MPI_Comm_rank(ptr noundef, ptr noundef) #2

declare i32 @MPI_Comm_size(ptr noundef, ptr noundef) #2

declare i32 @printf(ptr noundef, ...) #2

declare i32 @MPI_Abort(ptr noundef, i32 noundef) #2

declare i32 @MPI_Win_allocate(i64 noundef, i32 noundef, ptr noundef, ptr noundef, ptr noundef, ptr noundef) #2

declare i32 @MPI_Win_fence(i32 noundef, ptr noundef) #2

declare i32 @MPI_Put(ptr noundef, i32 noundef, ptr noundef, i32 noundef, i64 noundef, i32 noundef, ptr noundef, ptr noundef) #2

declare i32 @MPI_Get(ptr noundef, i32 noundef, ptr noundef, i32 noundef, i64 noundef, i32 noundef, ptr noundef, ptr noundef) #2

declare i32 @MPI_Barrier(ptr noundef) #2

declare i32 @MPI_Win_free(ptr noundef) #2

declare i32 @MPI_Finalize() #2

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nocallback nofree nosync nounwind readnone speculatable willreturn }
attributes #2 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.dbg.cu = !{!12}
!llvm.module.flags = !{!26, !27, !28, !29, !30, !31, !32, !33}
!llvm.ident = !{!34}

!0 = !DIGlobalVariableExpression(var: !1, expr: !DIExpression())
!1 = distinct !DIGlobalVariable(scope: null, file: !2, line: 47, type: !3, isLocal: true, isDefinition: true)
!2 = !DIFile(filename: "results-20240330-164421/PARCOACH-dynamic/sync/018-MPI-sync-fence-3procs-remote-yes.c", directory: "/rmaracebench", checksumkind: CSK_MD5, checksum: "65e4910fa7ee3f1d2bbb050dfe4dbadd")
!3 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 392, elements: !5)
!4 = !DIBasicType(name: "char", size: 8, encoding: DW_ATE_signed_char)
!5 = !{!6}
!6 = !DISubrange(count: 49)
!7 = !DIGlobalVariableExpression(var: !8, expr: !DIExpression())
!8 = distinct !DIGlobalVariable(scope: null, file: !2, line: 74, type: !9, isLocal: true, isDefinition: true)
!9 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 752, elements: !10)
!10 = !{!11}
!11 = !DISubrange(count: 94)
!12 = distinct !DICompileUnit(language: DW_LANG_C99, file: !2, producer: "Debian clang version 15.0.6", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, retainedTypes: !13, globals: !25, splitDebugInlining: false, nameTableKind: None)
!13 = !{!14, !18, !19, !22}
!14 = !DIDerivedType(tag: DW_TAG_typedef, name: "MPI_Comm", file: !15, line: 419, baseType: !16)
!15 = !DIFile(filename: "/usr/lib/x86_64-linux-gnu/openmpi/include/mpi.h", directory: "", checksumkind: CSK_MD5, checksum: "c3ca5be6f2c6a6e16d01846df47c0b49")
!16 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !17, size: 64)
!17 = !DICompositeType(tag: DW_TAG_structure_type, name: "ompi_communicator_t", file: !15, line: 419, flags: DIFlagFwdDecl)
!18 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: null, size: 64)
!19 = !DIDerivedType(tag: DW_TAG_typedef, name: "MPI_Info", file: !15, line: 424, baseType: !20)
!20 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !21, size: 64)
!21 = !DICompositeType(tag: DW_TAG_structure_type, name: "ompi_info_t", file: !15, line: 424, flags: DIFlagFwdDecl)
!22 = !DIDerivedType(tag: DW_TAG_typedef, name: "MPI_Datatype", file: !15, line: 420, baseType: !23)
!23 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !24, size: 64)
!24 = !DICompositeType(tag: DW_TAG_structure_type, name: "ompi_datatype_t", file: !15, line: 420, flags: DIFlagFwdDecl)
!25 = !{!0, !7}
!26 = !{i32 7, !"Dwarf Version", i32 5}
!27 = !{i32 2, !"Debug Info Version", i32 3}
!28 = !{i32 1, !"wchar_size", i32 4}
!29 = !{i32 7, !"openmp", i32 50}
!30 = !{i32 7, !"PIC Level", i32 2}
!31 = !{i32 7, !"PIE Level", i32 2}
!32 = !{i32 7, !"uwtable", i32 2}
!33 = !{i32 7, !"frame-pointer", i32 2}
!34 = !{!"Debian clang version 15.0.6"}
!35 = distinct !DISubprogram(name: "main", scope: !2, file: !2, line: 33, type: !36, scopeLine: 34, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !12, retainedNodes: !41)
!36 = !DISubroutineType(types: !37)
!37 = !{!38, !38, !39}
!38 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!39 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !40, size: 64)
!40 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !4, size: 64)
!41 = !{}
!42 = !DILocalVariable(name: "argc", arg: 1, scope: !35, file: !2, line: 33, type: !38)
!43 = !DILocation(line: 33, column: 14, scope: !35)
!44 = !DILocalVariable(name: "argv", arg: 2, scope: !35, file: !2, line: 33, type: !39)
!45 = !DILocation(line: 33, column: 27, scope: !35)
!46 = !DILocalVariable(name: "rank", scope: !35, file: !2, line: 35, type: !38)
!47 = !DILocation(line: 35, column: 9, scope: !35)
!48 = !DILocalVariable(name: "size", scope: !35, file: !2, line: 35, type: !38)
!49 = !DILocation(line: 35, column: 15, scope: !35)
!50 = !DILocalVariable(name: "win", scope: !35, file: !2, line: 36, type: !51)
!51 = !DIDerivedType(tag: DW_TAG_typedef, name: "MPI_Win", file: !15, line: 429, baseType: !52)
!52 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !53, size: 64)
!53 = !DICompositeType(tag: DW_TAG_structure_type, name: "ompi_win_t", file: !15, line: 429, flags: DIFlagFwdDecl)
!54 = !DILocation(line: 36, column: 13, scope: !35)
!55 = !DILocalVariable(name: "win_base", scope: !35, file: !2, line: 37, type: !56)
!56 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !38, size: 64)
!57 = !DILocation(line: 37, column: 10, scope: !35)
!58 = !DILocalVariable(name: "value", scope: !35, file: !2, line: 38, type: !38)
!59 = !DILocation(line: 38, column: 9, scope: !35)
!60 = !DILocalVariable(name: "value2", scope: !35, file: !2, line: 38, type: !38)
!61 = !DILocation(line: 38, column: 20, scope: !35)
!62 = !DILocalVariable(name: "result", scope: !35, file: !2, line: 39, type: !38)
!63 = !DILocation(line: 39, column: 9, scope: !35)
!64 = !DILocalVariable(name: "token", scope: !35, file: !2, line: 40, type: !38)
!65 = !DILocation(line: 40, column: 9, scope: !35)
!66 = !DILocation(line: 42, column: 5, scope: !35)
!67 = !DILocation(line: 43, column: 5, scope: !35)
!68 = !DILocation(line: 44, column: 5, scope: !35)
!69 = !DILocation(line: 46, column: 9, scope: !70)
!70 = distinct !DILexicalBlock(scope: !35, file: !2, line: 46, column: 9)
!71 = !DILocation(line: 46, column: 14, scope: !70)
!72 = !DILocation(line: 46, column: 9, scope: !35)
!73 = !DILocation(line: 47, column: 69, scope: !74)
!74 = distinct !DILexicalBlock(scope: !70, file: !2, line: 46, column: 27)
!75 = !DILocation(line: 47, column: 9, scope: !74)
!76 = !DILocation(line: 48, column: 9, scope: !74)
!77 = !DILocation(line: 49, column: 5, scope: !74)
!78 = !DILocation(line: 51, column: 5, scope: !35)
!79 = !DILocalVariable(name: "i", scope: !80, file: !2, line: 52, type: !38)
!80 = distinct !DILexicalBlock(scope: !35, file: !2, line: 52, column: 5)
!81 = !DILocation(line: 52, column: 14, scope: !80)
!82 = !DILocation(line: 52, column: 10, scope: !80)
!83 = !DILocation(line: 52, column: 21, scope: !84)
!84 = distinct !DILexicalBlock(scope: !80, file: !2, line: 52, column: 5)
!85 = !DILocation(line: 52, column: 23, scope: !84)
!86 = !DILocation(line: 52, column: 5, scope: !80)
!87 = !DILocation(line: 53, column: 9, scope: !88)
!88 = distinct !DILexicalBlock(scope: !84, file: !2, line: 52, column: 40)
!89 = !DILocation(line: 53, column: 18, scope: !88)
!90 = !DILocation(line: 53, column: 21, scope: !88)
!91 = !DILocation(line: 54, column: 5, scope: !88)
!92 = !DILocation(line: 52, column: 36, scope: !84)
!93 = !DILocation(line: 52, column: 5, scope: !84)
!94 = distinct !{!94, !86, !95, !96}
!95 = !DILocation(line: 54, column: 5, scope: !80)
!96 = !{!"llvm.loop.mustprogress"}
!97 = !DILocation(line: 56, column: 22, scope: !35)
!98 = !DILocation(line: 56, column: 5, scope: !35)
!99 = !DILocation(line: 58, column: 9, scope: !100)
!100 = distinct !DILexicalBlock(scope: !35, file: !2, line: 58, column: 9)
!101 = !DILocation(line: 58, column: 14, scope: !100)
!102 = !DILocation(line: 58, column: 9, scope: !35)
!103 = !DILocation(line: 59, column: 15, scope: !104)
!104 = distinct !DILexicalBlock(scope: !100, file: !2, line: 58, column: 20)
!105 = !DILocation(line: 61, column: 55, scope: !104)
!106 = !DILocation(line: 61, column: 9, scope: !104)
!107 = !DILocation(line: 62, column: 5, scope: !104)
!108 = !DILocation(line: 64, column: 9, scope: !109)
!109 = distinct !DILexicalBlock(scope: !35, file: !2, line: 64, column: 9)
!110 = !DILocation(line: 64, column: 14, scope: !109)
!111 = !DILocation(line: 64, column: 9, scope: !35)
!112 = !DILocation(line: 65, column: 15, scope: !113)
!113 = distinct !DILexicalBlock(scope: !109, file: !2, line: 64, column: 20)
!114 = !DILocation(line: 67, column: 55, scope: !113)
!115 = !DILocation(line: 67, column: 9, scope: !113)
!116 = !DILocation(line: 68, column: 5, scope: !113)
!117 = !DILocation(line: 70, column: 22, scope: !35)
!118 = !DILocation(line: 70, column: 5, scope: !35)
!119 = !DILocation(line: 72, column: 5, scope: !35)
!120 = !DILocation(line: 75, column: 9, scope: !35)
!121 = !DILocation(line: 76, column: 9, scope: !35)
!122 = !DILocation(line: 77, column: 9, scope: !35)
!123 = !DILocation(line: 78, column: 9, scope: !35)
!124 = !DILocation(line: 73, column: 5, scope: !35)
!125 = !DILocation(line: 80, column: 5, scope: !35)
!126 = !DILocation(line: 81, column: 5, scope: !35)
!127 = !DILocation(line: 83, column: 5, scope: !35)
