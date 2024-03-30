; ModuleID = 'results-20240330-164421/PARCOACH-dynamic/sync/036-MPI-sync-polling-remote-yes.c'
source_filename = "results-20240330-164421/PARCOACH-dynamic/sync/036-MPI-sync-polling-remote-yes.c"
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
  %15 = alloca i32, align 4
  %16 = alloca ptr, align 8
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
  %17 = call i32 @MPI_Init(ptr noundef %4, ptr noundef %5), !dbg !66
  %18 = call i32 @MPI_Comm_rank(ptr noundef @ompi_mpi_comm_world, ptr noundef %6), !dbg !67
  %19 = call i32 @MPI_Comm_size(ptr noundef @ompi_mpi_comm_world, ptr noundef %7), !dbg !68
  %20 = load i32, ptr %7, align 4, !dbg !69
  %21 = icmp ne i32 %20, 2, !dbg !71
  br i1 %21, label %22, label %26, !dbg !72

22:                                               ; preds = %2
  %23 = load i32, ptr %7, align 4, !dbg !73
  %24 = call i32 (ptr, ...) @printf(ptr noundef @.str, i32 noundef %23, i32 noundef 2), !dbg !75
  %25 = call i32 @MPI_Abort(ptr noundef @ompi_mpi_comm_world, i32 noundef 1), !dbg !76
  br label %26, !dbg !77

26:                                               ; preds = %22, %2
  %27 = call i32 @MPI_Win_allocate(i64 noundef 40, i32 noundef 4, ptr noundef @ompi_mpi_info_null, ptr noundef @ompi_mpi_comm_world, ptr noundef %9, ptr noundef %8), !dbg !78
  call void @llvm.dbg.declare(metadata ptr %14, metadata !79, metadata !DIExpression()), !dbg !81
  store i32 0, ptr %14, align 4, !dbg !81
  br label %28, !dbg !82

28:                                               ; preds = %36, %26
  %29 = load i32, ptr %14, align 4, !dbg !83
  %30 = icmp slt i32 %29, 10, !dbg !85
  br i1 %30, label %31, label %39, !dbg !86

31:                                               ; preds = %28
  %32 = load ptr, ptr %9, align 8, !dbg !87
  %33 = load i32, ptr %14, align 4, !dbg !89
  %34 = sext i32 %33 to i64, !dbg !87
  %35 = getelementptr inbounds i32, ptr %32, i64 %34, !dbg !87
  store i32 0, ptr %35, align 4, !dbg !90
  br label %36, !dbg !91

36:                                               ; preds = %31
  %37 = load i32, ptr %14, align 4, !dbg !92
  %38 = add nsw i32 %37, 1, !dbg !92
  store i32 %38, ptr %14, align 4, !dbg !92
  br label %28, !dbg !93, !llvm.loop !94

39:                                               ; preds = %28
  %40 = call i32 @MPI_Barrier(ptr noundef @ompi_mpi_comm_world), !dbg !97
  %41 = load i32, ptr %6, align 4, !dbg !98
  %42 = icmp eq i32 %41, 0, !dbg !100
  br i1 %42, label %43, label %50, !dbg !101

43:                                               ; preds = %39
  %44 = load ptr, ptr %8, align 8, !dbg !102
  %45 = call i32 @MPI_Win_lock(i32 noundef 1, i32 noundef 1, i32 noundef 0, ptr noundef %44), !dbg !104
  call void @llvm.dbg.declare(metadata ptr %15, metadata !105, metadata !DIExpression()), !dbg !106
  store i32 1, ptr %15, align 4, !dbg !106
  %46 = load ptr, ptr %8, align 8, !dbg !107
  %47 = call i32 @MPI_Put(ptr noundef %15, i32 noundef 1, ptr noundef @ompi_mpi_int, i32 noundef 1, i64 noundef 0, i32 noundef 1, ptr noundef @ompi_mpi_int, ptr noundef %46), !dbg !108
  %48 = load ptr, ptr %8, align 8, !dbg !109
  %49 = call i32 @MPI_Win_unlock(i32 noundef 1, ptr noundef %48), !dbg !110
  br label %64, !dbg !111

50:                                               ; preds = %39
  call void @llvm.dbg.declare(metadata ptr %16, metadata !112, metadata !DIExpression()), !dbg !116
  %51 = load ptr, ptr %9, align 8, !dbg !117
  %52 = getelementptr inbounds i32, ptr %51, i64 0, !dbg !117
  store ptr %52, ptr %16, align 8, !dbg !116
  br label %53, !dbg !118

53:                                               ; preds = %57, %50
  %54 = load ptr, ptr %16, align 8, !dbg !119
  %55 = load volatile i32, ptr %54, align 4, !dbg !120
  %56 = icmp ne i32 %55, 1, !dbg !121
  br i1 %56, label %57, label %63, !dbg !118

57:                                               ; preds = %53
  %58 = call i32 @sleep(i32 noundef 1), !dbg !122
  %59 = load ptr, ptr %8, align 8, !dbg !124
  %60 = call i32 @MPI_Win_lock(i32 noundef 1, i32 noundef 1, i32 noundef 0, ptr noundef %59), !dbg !125
  %61 = load ptr, ptr %8, align 8, !dbg !126
  %62 = call i32 @MPI_Win_unlock(i32 noundef 1, ptr noundef %61), !dbg !127
  br label %53, !dbg !118, !llvm.loop !128

63:                                               ; preds = %53
  br label %64

64:                                               ; preds = %63, %43
  %65 = call i32 @MPI_Barrier(ptr noundef @ompi_mpi_comm_world), !dbg !130
  %66 = call i32 @MPI_Barrier(ptr noundef @ompi_mpi_comm_world), !dbg !131
  %67 = load i32, ptr %6, align 4, !dbg !132
  %68 = load i32, ptr %10, align 4, !dbg !133
  %69 = load i32, ptr %11, align 4, !dbg !134
  %70 = load ptr, ptr %9, align 8, !dbg !135
  %71 = getelementptr inbounds i32, ptr %70, i64 0, !dbg !135
  %72 = load i32, ptr %71, align 4, !dbg !135
  %73 = call i32 (ptr, ...) @printf(ptr noundef @.str.1, i32 noundef %67, i32 noundef %68, i32 noundef %69, i32 noundef %72), !dbg !136
  %74 = call i32 @MPI_Win_free(ptr noundef %8), !dbg !137
  %75 = call i32 @MPI_Finalize(), !dbg !138
  ret i32 0, !dbg !139
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

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nocallback nofree nosync nounwind readnone speculatable willreturn }
attributes #2 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.dbg.cu = !{!12}
!llvm.module.flags = !{!26, !27, !28, !29, !30, !31, !32, !33}
!llvm.ident = !{!34}

!0 = !DIGlobalVariableExpression(var: !1, expr: !DIExpression())
!1 = distinct !DIGlobalVariable(scope: null, file: !2, line: 49, type: !3, isLocal: true, isDefinition: true)
!2 = !DIFile(filename: "results-20240330-164421/PARCOACH-dynamic/sync/036-MPI-sync-polling-remote-yes.c", directory: "/rmaracebench", checksumkind: CSK_MD5, checksum: "b0475c89f16be2c43dc817a506cc555b")
!3 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 392, elements: !5)
!4 = !DIBasicType(name: "char", size: 8, encoding: DW_ATE_signed_char)
!5 = !{!6}
!6 = !DISubrange(count: 49)
!7 = !DIGlobalVariableExpression(var: !8, expr: !DIExpression())
!8 = distinct !DIGlobalVariable(scope: null, file: !2, line: 83, type: !9, isLocal: true, isDefinition: true)
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
!35 = distinct !DISubprogram(name: "main", scope: !2, file: !2, line: 35, type: !36, scopeLine: 36, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !12, retainedNodes: !41)
!36 = !DISubroutineType(types: !37)
!37 = !{!38, !38, !39}
!38 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!39 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !40, size: 64)
!40 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !4, size: 64)
!41 = !{}
!42 = !DILocalVariable(name: "argc", arg: 1, scope: !35, file: !2, line: 35, type: !38)
!43 = !DILocation(line: 35, column: 14, scope: !35)
!44 = !DILocalVariable(name: "argv", arg: 2, scope: !35, file: !2, line: 35, type: !39)
!45 = !DILocation(line: 35, column: 27, scope: !35)
!46 = !DILocalVariable(name: "rank", scope: !35, file: !2, line: 37, type: !38)
!47 = !DILocation(line: 37, column: 9, scope: !35)
!48 = !DILocalVariable(name: "size", scope: !35, file: !2, line: 37, type: !38)
!49 = !DILocation(line: 37, column: 15, scope: !35)
!50 = !DILocalVariable(name: "win", scope: !35, file: !2, line: 38, type: !51)
!51 = !DIDerivedType(tag: DW_TAG_typedef, name: "MPI_Win", file: !15, line: 429, baseType: !52)
!52 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !53, size: 64)
!53 = !DICompositeType(tag: DW_TAG_structure_type, name: "ompi_win_t", file: !15, line: 429, flags: DIFlagFwdDecl)
!54 = !DILocation(line: 38, column: 13, scope: !35)
!55 = !DILocalVariable(name: "win_base", scope: !35, file: !2, line: 39, type: !56)
!56 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !38, size: 64)
!57 = !DILocation(line: 39, column: 10, scope: !35)
!58 = !DILocalVariable(name: "value", scope: !35, file: !2, line: 40, type: !38)
!59 = !DILocation(line: 40, column: 9, scope: !35)
!60 = !DILocalVariable(name: "value2", scope: !35, file: !2, line: 40, type: !38)
!61 = !DILocation(line: 40, column: 20, scope: !35)
!62 = !DILocalVariable(name: "result", scope: !35, file: !2, line: 41, type: !38)
!63 = !DILocation(line: 41, column: 9, scope: !35)
!64 = !DILocalVariable(name: "token", scope: !35, file: !2, line: 42, type: !38)
!65 = !DILocation(line: 42, column: 9, scope: !35)
!66 = !DILocation(line: 44, column: 5, scope: !35)
!67 = !DILocation(line: 45, column: 5, scope: !35)
!68 = !DILocation(line: 46, column: 5, scope: !35)
!69 = !DILocation(line: 48, column: 9, scope: !70)
!70 = distinct !DILexicalBlock(scope: !35, file: !2, line: 48, column: 9)
!71 = !DILocation(line: 48, column: 14, scope: !70)
!72 = !DILocation(line: 48, column: 9, scope: !35)
!73 = !DILocation(line: 49, column: 69, scope: !74)
!74 = distinct !DILexicalBlock(scope: !70, file: !2, line: 48, column: 27)
!75 = !DILocation(line: 49, column: 9, scope: !74)
!76 = !DILocation(line: 50, column: 9, scope: !74)
!77 = !DILocation(line: 51, column: 5, scope: !74)
!78 = !DILocation(line: 53, column: 5, scope: !35)
!79 = !DILocalVariable(name: "i", scope: !80, file: !2, line: 54, type: !38)
!80 = distinct !DILexicalBlock(scope: !35, file: !2, line: 54, column: 5)
!81 = !DILocation(line: 54, column: 14, scope: !80)
!82 = !DILocation(line: 54, column: 10, scope: !80)
!83 = !DILocation(line: 54, column: 21, scope: !84)
!84 = distinct !DILexicalBlock(scope: !80, file: !2, line: 54, column: 5)
!85 = !DILocation(line: 54, column: 23, scope: !84)
!86 = !DILocation(line: 54, column: 5, scope: !80)
!87 = !DILocation(line: 55, column: 9, scope: !88)
!88 = distinct !DILexicalBlock(scope: !84, file: !2, line: 54, column: 40)
!89 = !DILocation(line: 55, column: 18, scope: !88)
!90 = !DILocation(line: 55, column: 21, scope: !88)
!91 = !DILocation(line: 56, column: 5, scope: !88)
!92 = !DILocation(line: 54, column: 36, scope: !84)
!93 = !DILocation(line: 54, column: 5, scope: !84)
!94 = distinct !{!94, !86, !95, !96}
!95 = !DILocation(line: 56, column: 5, scope: !80)
!96 = !{!"llvm.loop.mustprogress"}
!97 = !DILocation(line: 58, column: 5, scope: !35)
!98 = !DILocation(line: 60, column: 9, scope: !99)
!99 = distinct !DILexicalBlock(scope: !35, file: !2, line: 60, column: 9)
!100 = !DILocation(line: 60, column: 14, scope: !99)
!101 = !DILocation(line: 60, column: 9, scope: !35)
!102 = !DILocation(line: 61, column: 48, scope: !103)
!103 = distinct !DILexicalBlock(scope: !99, file: !2, line: 60, column: 20)
!104 = !DILocation(line: 61, column: 9, scope: !103)
!105 = !DILocalVariable(name: "value", scope: !103, file: !2, line: 63, type: !38)
!106 = !DILocation(line: 63, column: 13, scope: !103)
!107 = !DILocation(line: 65, column: 55, scope: !103)
!108 = !DILocation(line: 65, column: 9, scope: !103)
!109 = !DILocation(line: 66, column: 27, scope: !103)
!110 = !DILocation(line: 66, column: 9, scope: !103)
!111 = !DILocation(line: 67, column: 5, scope: !103)
!112 = !DILocalVariable(name: "flag", scope: !113, file: !2, line: 69, type: !114)
!113 = distinct !DILexicalBlock(scope: !99, file: !2, line: 67, column: 12)
!114 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !115, size: 64)
!115 = !DIDerivedType(tag: DW_TAG_volatile_type, baseType: !38)
!116 = !DILocation(line: 69, column: 23, scope: !113)
!117 = !DILocation(line: 69, column: 31, scope: !113)
!118 = !DILocation(line: 71, column: 9, scope: !113)
!119 = !DILocation(line: 71, column: 17, scope: !113)
!120 = !DILocation(line: 71, column: 16, scope: !113)
!121 = !DILocation(line: 71, column: 22, scope: !113)
!122 = !DILocation(line: 72, column: 13, scope: !123)
!123 = distinct !DILexicalBlock(scope: !113, file: !2, line: 71, column: 28)
!124 = !DILocation(line: 74, column: 52, scope: !123)
!125 = !DILocation(line: 74, column: 13, scope: !123)
!126 = !DILocation(line: 75, column: 31, scope: !123)
!127 = !DILocation(line: 75, column: 13, scope: !123)
!128 = distinct !{!128, !118, !129, !96}
!129 = !DILocation(line: 76, column: 9, scope: !113)
!130 = !DILocation(line: 79, column: 5, scope: !35)
!131 = !DILocation(line: 81, column: 5, scope: !35)
!132 = !DILocation(line: 84, column: 9, scope: !35)
!133 = !DILocation(line: 85, column: 9, scope: !35)
!134 = !DILocation(line: 86, column: 9, scope: !35)
!135 = !DILocation(line: 87, column: 9, scope: !35)
!136 = !DILocation(line: 82, column: 5, scope: !35)
!137 = !DILocation(line: 89, column: 5, scope: !35)
!138 = !DILocation(line: 90, column: 5, scope: !35)
!139 = !DILocation(line: 92, column: 5, scope: !35)
