; ModuleID = 'results-20240330-164421/PARCOACH-dynamic/atomic/004-MPI-atomic-disp-remote-no.c'
source_filename = "results-20240330-164421/PARCOACH-dynamic/atomic/004-MPI-atomic-disp-remote-no.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct.ompi_predefined_communicator_t = type opaque
%struct.ompi_predefined_info_t = type opaque
%struct.ompi_predefined_datatype_t = type opaque
%struct.ompi_predefined_op_t = type opaque

@ompi_mpi_comm_world = external global %struct.ompi_predefined_communicator_t, align 1
@.str = private unnamed_addr constant [49 x i8] c"Wrong number of MPI processes: %d. Expected: %d\0A\00", align 1, !dbg !0
@ompi_mpi_info_null = external global %struct.ompi_predefined_info_t, align 1
@__const.main.value1 = private unnamed_addr constant [4 x i32] [i32 1, i32 1, i32 1, i32 1], align 16
@ompi_mpi_int = external global %struct.ompi_predefined_datatype_t, align 1
@ompi_mpi_op_sum = external global %struct.ompi_predefined_op_t, align 1
@__const.main.value2 = private unnamed_addr constant [4 x i32] [i32 1, i32 2, i32 3, i32 4], align 16
@.str.1 = private unnamed_addr constant [94 x i8] c"Process %d: Execution finished, variable contents: value = %d, value2 = %d, win_base[0] = %d\0A\00", align 1, !dbg !7

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main(i32 noundef %0, ptr noundef %1) #0 !dbg !38 {
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
  %15 = alloca [4 x i32], align 16
  %16 = alloca [4 x i32], align 16
  %17 = alloca i32, align 4
  store i32 0, ptr %3, align 4
  store i32 %0, ptr %4, align 4
  call void @llvm.dbg.declare(metadata ptr %4, metadata !45, metadata !DIExpression()), !dbg !46
  store ptr %1, ptr %5, align 8
  call void @llvm.dbg.declare(metadata ptr %5, metadata !47, metadata !DIExpression()), !dbg !48
  call void @llvm.dbg.declare(metadata ptr %6, metadata !49, metadata !DIExpression()), !dbg !50
  call void @llvm.dbg.declare(metadata ptr %7, metadata !51, metadata !DIExpression()), !dbg !52
  call void @llvm.dbg.declare(metadata ptr %8, metadata !53, metadata !DIExpression()), !dbg !57
  call void @llvm.dbg.declare(metadata ptr %9, metadata !58, metadata !DIExpression()), !dbg !60
  call void @llvm.dbg.declare(metadata ptr %10, metadata !61, metadata !DIExpression()), !dbg !62
  store i32 1, ptr %10, align 4, !dbg !62
  call void @llvm.dbg.declare(metadata ptr %11, metadata !63, metadata !DIExpression()), !dbg !64
  store i32 2, ptr %11, align 4, !dbg !64
  call void @llvm.dbg.declare(metadata ptr %12, metadata !65, metadata !DIExpression()), !dbg !66
  call void @llvm.dbg.declare(metadata ptr %13, metadata !67, metadata !DIExpression()), !dbg !68
  store i32 42, ptr %13, align 4, !dbg !68
  %18 = call i32 @MPI_Init(ptr noundef %4, ptr noundef %5), !dbg !69
  %19 = call i32 @MPI_Comm_rank(ptr noundef @ompi_mpi_comm_world, ptr noundef %6), !dbg !70
  %20 = call i32 @MPI_Comm_size(ptr noundef @ompi_mpi_comm_world, ptr noundef %7), !dbg !71
  %21 = load i32, ptr %7, align 4, !dbg !72
  %22 = icmp ne i32 %21, 3, !dbg !74
  br i1 %22, label %23, label %27, !dbg !75

23:                                               ; preds = %2
  %24 = load i32, ptr %7, align 4, !dbg !76
  %25 = call i32 (ptr, ...) @printf(ptr noundef @.str, i32 noundef %24, i32 noundef 3), !dbg !78
  %26 = call i32 @MPI_Abort(ptr noundef @ompi_mpi_comm_world, i32 noundef 1), !dbg !79
  br label %27, !dbg !80

27:                                               ; preds = %23, %2
  %28 = call i32 @MPI_Win_allocate(i64 noundef 40, i32 noundef 1, ptr noundef @ompi_mpi_info_null, ptr noundef @ompi_mpi_comm_world, ptr noundef %9, ptr noundef %8), !dbg !81
  call void @llvm.dbg.declare(metadata ptr %14, metadata !82, metadata !DIExpression()), !dbg !84
  store i32 0, ptr %14, align 4, !dbg !84
  br label %29, !dbg !85

29:                                               ; preds = %37, %27
  %30 = load i32, ptr %14, align 4, !dbg !86
  %31 = icmp slt i32 %30, 10, !dbg !88
  br i1 %31, label %32, label %40, !dbg !89

32:                                               ; preds = %29
  %33 = load ptr, ptr %9, align 8, !dbg !90
  %34 = load i32, ptr %14, align 4, !dbg !92
  %35 = sext i32 %34 to i64, !dbg !90
  %36 = getelementptr inbounds i32, ptr %33, i64 %35, !dbg !90
  store i32 0, ptr %36, align 4, !dbg !93
  br label %37, !dbg !94

37:                                               ; preds = %32
  %38 = load i32, ptr %14, align 4, !dbg !95
  %39 = add nsw i32 %38, 1, !dbg !95
  store i32 %39, ptr %14, align 4, !dbg !95
  br label %29, !dbg !96, !llvm.loop !97

40:                                               ; preds = %29
  %41 = call i32 @MPI_Barrier(ptr noundef @ompi_mpi_comm_world), !dbg !100
  %42 = load ptr, ptr %8, align 8, !dbg !101
  %43 = call i32 @MPI_Win_fence(i32 noundef 0, ptr noundef %42), !dbg !102
  %44 = load i32, ptr %6, align 4, !dbg !103
  %45 = icmp eq i32 %44, 0, !dbg !105
  br i1 %45, label %46, label %50, !dbg !106

46:                                               ; preds = %40
  call void @llvm.dbg.declare(metadata ptr %15, metadata !107, metadata !DIExpression()), !dbg !112
  call void @llvm.memcpy.p0.p0.i64(ptr align 16 %15, ptr align 16 @__const.main.value1, i64 16, i1 false), !dbg !112
  %47 = getelementptr inbounds [4 x i32], ptr %15, i64 0, i64 0, !dbg !113
  %48 = load ptr, ptr %8, align 8, !dbg !114
  %49 = call i32 @MPI_Accumulate(ptr noundef %47, i32 noundef 4, ptr noundef @ompi_mpi_int, i32 noundef 1, i64 noundef 0, i32 noundef 4, ptr noundef @ompi_mpi_int, ptr noundef @ompi_mpi_op_sum, ptr noundef %48), !dbg !115
  br label %50, !dbg !116

50:                                               ; preds = %46, %40
  %51 = load i32, ptr %6, align 4, !dbg !117
  %52 = icmp eq i32 %51, 2, !dbg !119
  br i1 %52, label %53, label %60, !dbg !120

53:                                               ; preds = %50
  call void @llvm.dbg.declare(metadata ptr %16, metadata !121, metadata !DIExpression()), !dbg !123
  call void @llvm.memcpy.p0.p0.i64(ptr align 16 %16, ptr align 16 @__const.main.value2, i64 16, i1 false), !dbg !123
  call void @llvm.dbg.declare(metadata ptr %17, metadata !124, metadata !DIExpression()), !dbg !125
  %54 = call i32 @MPI_Type_size(ptr noundef @ompi_mpi_int, ptr noundef %17), !dbg !126
  %55 = getelementptr inbounds [4 x i32], ptr %16, i64 0, i64 0, !dbg !127
  %56 = load i32, ptr %17, align 4, !dbg !128
  %57 = sext i32 %56 to i64, !dbg !128
  %58 = load ptr, ptr %8, align 8, !dbg !129
  %59 = call i32 @MPI_Accumulate(ptr noundef %55, i32 noundef 4, ptr noundef @ompi_mpi_int, i32 noundef 1, i64 noundef %57, i32 noundef 4, ptr noundef @ompi_mpi_int, ptr noundef @ompi_mpi_op_sum, ptr noundef %58), !dbg !130
  br label %60, !dbg !131

60:                                               ; preds = %53, %50
  %61 = load ptr, ptr %8, align 8, !dbg !132
  %62 = call i32 @MPI_Win_fence(i32 noundef 0, ptr noundef %61), !dbg !133
  %63 = call i32 @MPI_Barrier(ptr noundef @ompi_mpi_comm_world), !dbg !134
  %64 = load i32, ptr %6, align 4, !dbg !135
  %65 = load i32, ptr %10, align 4, !dbg !136
  %66 = load i32, ptr %11, align 4, !dbg !137
  %67 = load ptr, ptr %9, align 8, !dbg !138
  %68 = getelementptr inbounds i32, ptr %67, i64 0, !dbg !138
  %69 = load i32, ptr %68, align 4, !dbg !138
  %70 = call i32 (ptr, ...) @printf(ptr noundef @.str.1, i32 noundef %64, i32 noundef %65, i32 noundef %66, i32 noundef %69), !dbg !139
  %71 = call i32 @MPI_Win_free(ptr noundef %8), !dbg !140
  %72 = call i32 @MPI_Finalize(), !dbg !141
  ret i32 0, !dbg !142
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

declare i32 @MPI_Win_fence(i32 noundef, ptr noundef) #2

; Function Attrs: argmemonly nocallback nofree nounwind willreturn
declare void @llvm.memcpy.p0.p0.i64(ptr noalias nocapture writeonly, ptr noalias nocapture readonly, i64, i1 immarg) #3

declare i32 @MPI_Accumulate(ptr noundef, i32 noundef, ptr noundef, i32 noundef, i64 noundef, i32 noundef, ptr noundef, ptr noundef, ptr noundef) #2

declare i32 @MPI_Type_size(ptr noundef, ptr noundef) #2

declare i32 @MPI_Win_free(ptr noundef) #2

declare i32 @MPI_Finalize() #2

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nocallback nofree nosync nounwind readnone speculatable willreturn }
attributes #2 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #3 = { argmemonly nocallback nofree nounwind willreturn }

!llvm.dbg.cu = !{!12}
!llvm.module.flags = !{!29, !30, !31, !32, !33, !34, !35, !36}
!llvm.ident = !{!37}

!0 = !DIGlobalVariableExpression(var: !1, expr: !DIExpression())
!1 = distinct !DIGlobalVariable(scope: null, file: !2, line: 44, type: !3, isLocal: true, isDefinition: true)
!2 = !DIFile(filename: "results-20240330-164421/PARCOACH-dynamic/atomic/004-MPI-atomic-disp-remote-no.c", directory: "/rmaracebench", checksumkind: CSK_MD5, checksum: "485a1d152e444f738ebd4b03229e00b8")
!3 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 392, elements: !5)
!4 = !DIBasicType(name: "char", size: 8, encoding: DW_ATE_signed_char)
!5 = !{!6}
!6 = !DISubrange(count: 49)
!7 = !DIGlobalVariableExpression(var: !8, expr: !DIExpression())
!8 = distinct !DIGlobalVariable(scope: null, file: !2, line: 71, type: !9, isLocal: true, isDefinition: true)
!9 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 752, elements: !10)
!10 = !{!11}
!11 = !DISubrange(count: 94)
!12 = distinct !DICompileUnit(language: DW_LANG_C99, file: !2, producer: "Debian clang version 15.0.6", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, retainedTypes: !13, globals: !28, splitDebugInlining: false, nameTableKind: None)
!13 = !{!14, !18, !19, !22, !25}
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
!25 = !DIDerivedType(tag: DW_TAG_typedef, name: "MPI_Op", file: !15, line: 425, baseType: !26)
!26 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !27, size: 64)
!27 = !DICompositeType(tag: DW_TAG_structure_type, name: "ompi_op_t", file: !15, line: 425, flags: DIFlagFwdDecl)
!28 = !{!0, !7}
!29 = !{i32 7, !"Dwarf Version", i32 5}
!30 = !{i32 2, !"Debug Info Version", i32 3}
!31 = !{i32 1, !"wchar_size", i32 4}
!32 = !{i32 7, !"openmp", i32 50}
!33 = !{i32 7, !"PIC Level", i32 2}
!34 = !{i32 7, !"PIE Level", i32 2}
!35 = !{i32 7, !"uwtable", i32 2}
!36 = !{i32 7, !"frame-pointer", i32 2}
!37 = !{!"Debian clang version 15.0.6"}
!38 = distinct !DISubprogram(name: "main", scope: !2, file: !2, line: 30, type: !39, scopeLine: 31, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !12, retainedNodes: !44)
!39 = !DISubroutineType(types: !40)
!40 = !{!41, !41, !42}
!41 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!42 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !43, size: 64)
!43 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !4, size: 64)
!44 = !{}
!45 = !DILocalVariable(name: "argc", arg: 1, scope: !38, file: !2, line: 30, type: !41)
!46 = !DILocation(line: 30, column: 14, scope: !38)
!47 = !DILocalVariable(name: "argv", arg: 2, scope: !38, file: !2, line: 30, type: !42)
!48 = !DILocation(line: 30, column: 27, scope: !38)
!49 = !DILocalVariable(name: "rank", scope: !38, file: !2, line: 32, type: !41)
!50 = !DILocation(line: 32, column: 9, scope: !38)
!51 = !DILocalVariable(name: "size", scope: !38, file: !2, line: 32, type: !41)
!52 = !DILocation(line: 32, column: 15, scope: !38)
!53 = !DILocalVariable(name: "win", scope: !38, file: !2, line: 33, type: !54)
!54 = !DIDerivedType(tag: DW_TAG_typedef, name: "MPI_Win", file: !15, line: 429, baseType: !55)
!55 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !56, size: 64)
!56 = !DICompositeType(tag: DW_TAG_structure_type, name: "ompi_win_t", file: !15, line: 429, flags: DIFlagFwdDecl)
!57 = !DILocation(line: 33, column: 13, scope: !38)
!58 = !DILocalVariable(name: "win_base", scope: !38, file: !2, line: 34, type: !59)
!59 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !41, size: 64)
!60 = !DILocation(line: 34, column: 10, scope: !38)
!61 = !DILocalVariable(name: "value", scope: !38, file: !2, line: 35, type: !41)
!62 = !DILocation(line: 35, column: 9, scope: !38)
!63 = !DILocalVariable(name: "value2", scope: !38, file: !2, line: 35, type: !41)
!64 = !DILocation(line: 35, column: 20, scope: !38)
!65 = !DILocalVariable(name: "result", scope: !38, file: !2, line: 36, type: !41)
!66 = !DILocation(line: 36, column: 9, scope: !38)
!67 = !DILocalVariable(name: "token", scope: !38, file: !2, line: 37, type: !41)
!68 = !DILocation(line: 37, column: 9, scope: !38)
!69 = !DILocation(line: 39, column: 5, scope: !38)
!70 = !DILocation(line: 40, column: 5, scope: !38)
!71 = !DILocation(line: 41, column: 5, scope: !38)
!72 = !DILocation(line: 43, column: 9, scope: !73)
!73 = distinct !DILexicalBlock(scope: !38, file: !2, line: 43, column: 9)
!74 = !DILocation(line: 43, column: 14, scope: !73)
!75 = !DILocation(line: 43, column: 9, scope: !38)
!76 = !DILocation(line: 44, column: 69, scope: !77)
!77 = distinct !DILexicalBlock(scope: !73, file: !2, line: 43, column: 27)
!78 = !DILocation(line: 44, column: 9, scope: !77)
!79 = !DILocation(line: 45, column: 9, scope: !77)
!80 = !DILocation(line: 46, column: 5, scope: !77)
!81 = !DILocation(line: 48, column: 5, scope: !38)
!82 = !DILocalVariable(name: "i", scope: !83, file: !2, line: 49, type: !41)
!83 = distinct !DILexicalBlock(scope: !38, file: !2, line: 49, column: 5)
!84 = !DILocation(line: 49, column: 14, scope: !83)
!85 = !DILocation(line: 49, column: 10, scope: !83)
!86 = !DILocation(line: 49, column: 21, scope: !87)
!87 = distinct !DILexicalBlock(scope: !83, file: !2, line: 49, column: 5)
!88 = !DILocation(line: 49, column: 23, scope: !87)
!89 = !DILocation(line: 49, column: 5, scope: !83)
!90 = !DILocation(line: 50, column: 9, scope: !91)
!91 = distinct !DILexicalBlock(scope: !87, file: !2, line: 49, column: 40)
!92 = !DILocation(line: 50, column: 18, scope: !91)
!93 = !DILocation(line: 50, column: 21, scope: !91)
!94 = !DILocation(line: 51, column: 5, scope: !91)
!95 = !DILocation(line: 49, column: 36, scope: !87)
!96 = !DILocation(line: 49, column: 5, scope: !87)
!97 = distinct !{!97, !89, !98, !99}
!98 = !DILocation(line: 51, column: 5, scope: !83)
!99 = !{!"llvm.loop.mustprogress"}
!100 = !DILocation(line: 53, column: 5, scope: !38)
!101 = !DILocation(line: 55, column: 22, scope: !38)
!102 = !DILocation(line: 55, column: 5, scope: !38)
!103 = !DILocation(line: 56, column: 9, scope: !104)
!104 = distinct !DILexicalBlock(scope: !38, file: !2, line: 56, column: 9)
!105 = !DILocation(line: 56, column: 14, scope: !104)
!106 = !DILocation(line: 56, column: 9, scope: !38)
!107 = !DILocalVariable(name: "value1", scope: !108, file: !2, line: 57, type: !109)
!108 = distinct !DILexicalBlock(scope: !104, file: !2, line: 56, column: 20)
!109 = !DICompositeType(tag: DW_TAG_array_type, baseType: !41, size: 128, elements: !110)
!110 = !{!111}
!111 = !DISubrange(count: 4)
!112 = !DILocation(line: 57, column: 13, scope: !108)
!113 = !DILocation(line: 59, column: 24, scope: !108)
!114 = !DILocation(line: 59, column: 71, scope: !108)
!115 = !DILocation(line: 59, column: 9, scope: !108)
!116 = !DILocation(line: 60, column: 5, scope: !108)
!117 = !DILocation(line: 61, column: 9, scope: !118)
!118 = distinct !DILexicalBlock(scope: !38, file: !2, line: 61, column: 9)
!119 = !DILocation(line: 61, column: 14, scope: !118)
!120 = !DILocation(line: 61, column: 9, scope: !38)
!121 = !DILocalVariable(name: "value2", scope: !122, file: !2, line: 62, type: !109)
!122 = distinct !DILexicalBlock(scope: !118, file: !2, line: 61, column: 20)
!123 = !DILocation(line: 62, column: 13, scope: !122)
!124 = !DILocalVariable(name: "typesize", scope: !122, file: !2, line: 63, type: !41)
!125 = !DILocation(line: 63, column: 13, scope: !122)
!126 = !DILocation(line: 64, column: 9, scope: !122)
!127 = !DILocation(line: 65, column: 24, scope: !122)
!128 = !DILocation(line: 65, column: 47, scope: !122)
!129 = !DILocation(line: 65, column: 78, scope: !122)
!130 = !DILocation(line: 65, column: 9, scope: !122)
!131 = !DILocation(line: 66, column: 5, scope: !122)
!132 = !DILocation(line: 67, column: 22, scope: !38)
!133 = !DILocation(line: 67, column: 5, scope: !38)
!134 = !DILocation(line: 69, column: 5, scope: !38)
!135 = !DILocation(line: 72, column: 9, scope: !38)
!136 = !DILocation(line: 73, column: 9, scope: !38)
!137 = !DILocation(line: 74, column: 9, scope: !38)
!138 = !DILocation(line: 75, column: 9, scope: !38)
!139 = !DILocation(line: 70, column: 5, scope: !38)
!140 = !DILocation(line: 77, column: 5, scope: !38)
!141 = !DILocation(line: 78, column: 5, scope: !38)
!142 = !DILocation(line: 80, column: 5, scope: !38)
