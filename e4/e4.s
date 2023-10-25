	.file	"e4.cpp"
 # GNU C++17 (x86_64-posix-seh-rev1, Built by MinGW-W64 project) version 11.2.0 (x86_64-w64-mingw32)
 #	compiled by GNU C version 11.2.0, GMP version 6.2.1, MPFR version 4.1.0, MPC version 1.2.1, isl version isl-0.24-GMP

 # GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
 # options passed: -mtune=core2 -march=nocona -O2
	.text
	.section	.text$_ZNKSt5ctypeIcE8do_widenEc,"x"
	.linkonce discard
	.align 2
	.p2align 4
	.globl	_ZNKSt5ctypeIcE8do_widenEc
	.def	_ZNKSt5ctypeIcE8do_widenEc;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNKSt5ctypeIcE8do_widenEc
_ZNKSt5ctypeIcE8do_widenEc:
.LFB1594:
	.seh_endprologue
 # D:/RedPanda-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/11.2.0/include/c++/bits/locale_facets.h:1087:       do_widen(char __c) const
	movl	%edx, %eax	 # tmp87, __c
 # D:/RedPanda-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/11.2.0/include/c++/bits/locale_facets.h:1088:       { return __c; }
	ret	
	.seh_endproc
	.text
	.p2align 4
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB2331:
	.seh_endprologue
 # D:/RedPanda-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/11.2.0/include/c++/iostream:74:   static ios_base::Init __ioinit;
	leaq	_ZStL8__ioinit(%rip), %rcx	 #, tmp82
	jmp	_ZNSt8ios_base4InitD1Ev	 #
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii " \0"
	.section	.text.startup,"x"
	.p2align 4
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB1841:
	pushq	%rbp	 #
	.seh_pushreg	%rbp
	pushq	%r15	 #
	.seh_pushreg	%r15
	pushq	%r14	 #
	.seh_pushreg	%r14
	pushq	%r13	 #
	.seh_pushreg	%r13
	pushq	%r12	 #
	.seh_pushreg	%r12
	pushq	%rdi	 #
	.seh_pushreg	%rdi
	pushq	%rsi	 #
	.seh_pushreg	%rsi
	pushq	%rbx	 #
	.seh_pushreg	%rbx
	subq	$72, %rsp	 #,
	.seh_stackalloc	72
	leaq	64(%rsp), %rbp	 #,
	.seh_setframe	%rbp, 64
	.seh_endprologue
 # D:/c++_school_work/e4/e4.cpp:4: int main() {
	call	__main	 #
 # D:/c++_school_work/e4/e4.cpp:6: 	cin>>n>>m;
	movq	.refptr._ZSt3cin(%rip), %rdi	 #, tmp155
	leaq	-8(%rbp), %rdx	 #, tmp121
	movq	%rdi, %rcx	 # tmp155,
	call	_ZNSirsERi	 #
 # D:/c++_school_work/e4/e4.cpp:6: 	cin>>n>>m;
	leaq	-4(%rbp), %rdx	 #, tmp123
 # D:/c++_school_work/e4/e4.cpp:6: 	cin>>n>>m;
	movq	%rax, %rcx	 # tmp160, _26
 # D:/c++_school_work/e4/e4.cpp:6: 	cin>>n>>m;
	call	_ZNSirsERi	 #
 # D:/c++_school_work/e4/e4.cpp:7: 	int matrix[n][m];
	movslq	-4(%rbp), %r8	 # m,
	movslq	-8(%rbp), %rax	 # n,
 # D:/c++_school_work/e4/e4.cpp:7: 	int matrix[n][m];
	leaq	0(,%r8,4), %rbx	 #, _2
 # D:/c++_school_work/e4/e4.cpp:7: 	int matrix[n][m];
	movq	%r8, %rcx	 #,
	movq	%rax, %rdx	 #,
 # D:/c++_school_work/e4/e4.cpp:7: 	int matrix[n][m];
	movq	%rbx, -24(%rbp)	 # _2, %sfp
	imulq	%r8, %rax	 # _1, tmp125
	leaq	15(,%rax,4), %rax	 #, tmp127
	andq	$-16, %rax	 #, tmp129
	call	___chkstk_ms
	subq	%rax, %rsp	 # tmp131,
 # D:/c++_school_work/e4/e4.cpp:8: 	for(int i = 0;i<n;i++) {
	testl	%edx, %edx	 # n.1_29
 # D:/c++_school_work/e4/e4.cpp:7: 	int matrix[n][m];
	leaq	32(%rsp), %rsi	 #, tmp134
 # D:/c++_school_work/e4/e4.cpp:8: 	for(int i = 0;i<n;i++) {
	jle	.L5	 #,
 # D:/c++_school_work/e4/e4.cpp:10: 			cin>>matrix[i][j];
	shrq	$2, %rbx	 #, _6
	xorl	%r14d, %r14d	 # ivtmp.63
 # D:/c++_school_work/e4/e4.cpp:8: 	for(int i = 0;i<n;i++) {
	xorl	%r13d, %r13d	 # i
 # D:/c++_school_work/e4/e4.cpp:10: 			cin>>matrix[i][j];
	movq	%rbx, %r15	 # _6, _6
	.p2align 4,,10
	.p2align 3
.L6:
	leaq	(%rsi,%r14,4), %r12	 #, ivtmp.58
 # D:/c++_school_work/e4/e4.cpp:9: 		for(int j = 0;j<m;j++) {
	xorl	%ebx, %ebx	 # j
 # D:/c++_school_work/e4/e4.cpp:9: 		for(int j = 0;j<m;j++) {
	testl	%ecx, %ecx	 # prephitmp_90
	jle	.L9	 #,
	.p2align 4,,10
	.p2align 3
.L7:
 # D:/c++_school_work/e4/e4.cpp:10: 			cin>>matrix[i][j];
	movq	%r12, %rdx	 # ivtmp.58,
	movq	%rdi, %rcx	 # tmp155,
 # D:/c++_school_work/e4/e4.cpp:9: 		for(int j = 0;j<m;j++) {
	addl	$1, %ebx	 #, j
 # D:/c++_school_work/e4/e4.cpp:10: 			cin>>matrix[i][j];
	call	_ZNSirsERi	 #
 # D:/c++_school_work/e4/e4.cpp:9: 		for(int j = 0;j<m;j++) {
	movl	-4(%rbp), %ecx	 # m, prephitmp_90
	addq	$4, %r12	 #, ivtmp.58
	cmpl	%ebx, %ecx	 # j, prephitmp_90
	jg	.L7	 #,
.L9:
 # D:/c++_school_work/e4/e4.cpp:8: 	for(int i = 0;i<n;i++) {
	addl	$1, %r13d	 #, i
 # D:/c++_school_work/e4/e4.cpp:8: 	for(int i = 0;i<n;i++) {
	addq	%r15, %r14	 # _6, ivtmp.63
	cmpl	%r13d, -8(%rbp)	 # i, n
	jg	.L6	 #,
.L5:
 # D:/c++_school_work/e4/e4.cpp:13: 	for(int i = 0;i<m;i++) {
	testl	%ecx, %ecx	 # prephitmp_90
	jle	.L26	 #,
 # D:/c++_school_work/e4/e4.cpp:15: 			cout << matrix[j][i]<<" ";
	movq	-24(%rbp), %r12	 # %sfp, _2
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rax	 #, tmp158
 # D:/c++_school_work/e4/e4.cpp:13: 	for(int i = 0;i<m;i++) {
	xorl	%r14d, %r14d	 # i
	movq	.refptr._ZSt4cout(%rip), %rbx	 #, tmp156
	leaq	.LC0(%rip), %r13	 #, tmp157
	movq	%rax, -24(%rbp)	 # tmp158, %sfp
 # D:/c++_school_work/e4/e4.cpp:15: 			cout << matrix[j][i]<<" ";
	shrq	$2, %r12	 #, _2
	.p2align 4,,10
	.p2align 3
.L17:
 # D:/c++_school_work/e4/e4.cpp:14: 		for(int j = n - 1;j>=0;j--) {
	movl	-8(%rbp), %r15d	 # n, j
	movslq	%r14d, %rdi	 # i, i
	subl	$1, %r15d	 #, j
	js	.L14	 #,
	.p2align 4,,10
	.p2align 3
.L11:
 # D:/c++_school_work/e4/e4.cpp:15: 			cout << matrix[j][i]<<" ";
	movslq	%r15d, %rax	 # j, j
	movq	%rbx, %rcx	 # tmp156,
	imulq	%r12, %rax	 # _11, tmp145
	addq	%rdi, %rax	 # i, tmp146
	movl	(%rsi,%rax,4), %edx	 # (*matrix.2_31)[j_65]{lb: 0 sz: _11 * 4}[i_83], (*matrix.2_31)[j_65]{lb: 0 sz: _11 * 4}[i_83]
	call	_ZNSolsEi	 #
 # D:/RedPanda-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/11.2.0/include/c++/ostream:611: 	__ostream_insert(__out, __s,
	movl	$1, %r8d	 #,
	movq	%r13, %rdx	 # tmp157,
 # D:/c++_school_work/e4/e4.cpp:15: 			cout << matrix[j][i]<<" ";
	movq	%rax, %rcx	 # tmp161, _38
 # D:/RedPanda-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/11.2.0/include/c++/ostream:611: 	__ostream_insert(__out, __s,
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x	 #
 # D:/c++_school_work/e4/e4.cpp:14: 		for(int j = n - 1;j>=0;j--) {
	subl	$1, %r15d	 #, j
	jnb	.L11	 #,
.L14:
 # D:/RedPanda-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/11.2.0/include/c++/ostream:682:     { return flush(__os.put(__os.widen('\n'))); }
	movq	(%rbx), %rax	 # cout._vptr.basic_ostream, cout._vptr.basic_ostream
	movq	-24(%rax), %rax	 # MEM[(long long int *)_47 + -24B], MEM[(long long int *)_47 + -24B]
	movq	240(%rax,%rbx), %rdi	 # MEM[(const struct __ctype_type * *)_50 + 240B], _55
 # D:/RedPanda-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/11.2.0/include/c++/bits/basic_ios.h:49:       if (!__f)
	testq	%rdi, %rdi	 # _55
	je	.L28	 #,
 # D:/RedPanda-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/11.2.0/include/c++/bits/locale_facets.h:877: 	if (_M_widen_ok)
	cmpb	$0, 56(%rdi)	 #, MEM[(const struct ctype *)_55]._M_widen_ok
	je	.L15	 #,
 # D:/RedPanda-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/11.2.0/include/c++/ostream:682:     { return flush(__os.put(__os.widen('\n'))); }
	movsbl	67(%rdi), %edx	 # MEM[(const struct ctype *)_55]._M_widen[10], _93
.L16:
	movq	%rbx, %rcx	 # tmp156,
 # D:/c++_school_work/e4/e4.cpp:13: 	for(int i = 0;i<m;i++) {
	addl	$1, %r14d	 #, i
 # D:/RedPanda-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/11.2.0/include/c++/ostream:682:     { return flush(__os.put(__os.widen('\n'))); }
	call	_ZNSo3putEc	 #
	movq	%rax, %rcx	 # tmp163, _53
 # D:/RedPanda-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/11.2.0/include/c++/ostream:704:     { return __os.flush(); }
	call	_ZNSo5flushEv	 #
 # D:/c++_school_work/e4/e4.cpp:13: 	for(int i = 0;i<m;i++) {
	cmpl	%r14d, -4(%rbp)	 # i, m
	jg	.L17	 #,
.L26:
 # D:/c++_school_work/e4/e4.cpp:20: }
	xorl	%eax, %eax	 #
	leaq	8(%rbp), %rsp	 #,
	popq	%rbx	 #
	popq	%rsi	 #
	popq	%rdi	 #
	popq	%r12	 #
	popq	%r13	 #
	popq	%r14	 #
	popq	%r15	 #
	popq	%rbp	 #
	ret	
	.p2align 4,,10
	.p2align 3
.L15:
 # D:/RedPanda-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/11.2.0/include/c++/bits/locale_facets.h:879: 	this->_M_widen_init();
	movq	%rdi, %rcx	 # _55,
	call	_ZNKSt5ctypeIcE13_M_widen_initEv	 #
 # D:/RedPanda-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/11.2.0/include/c++/bits/locale_facets.h:880: 	return this->do_widen(__c);
	movq	(%rdi), %rax	 # MEM[(const struct ctype *)_55].D.39001._vptr.facet, MEM[(const struct ctype *)_55].D.39001._vptr.facet
	movl	$10, %edx	 #, _93
	movq	48(%rax), %rax	 # MEM[(int (*) () *)_68 + 48B], _69
	cmpq	-24(%rbp), %rax	 # %sfp, _69
	je	.L16	 #,
	movq	%rdi, %rcx	 # _55,
	call	*%rax	 # _69
 # D:/RedPanda-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/11.2.0/include/c++/ostream:682:     { return flush(__os.put(__os.widen('\n'))); }
	movsbl	%al, %edx	 # tmp162, _93
	jmp	.L16	 #
.L28:
 # D:/RedPanda-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/11.2.0/include/c++/bits/basic_ios.h:50: 	__throw_bad_cast();
	call	_ZSt16__throw_bad_castv	 #
	nop	
	.seh_endproc
	.p2align 4
	.def	_GLOBAL__sub_I_main;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I_main
_GLOBAL__sub_I_main:
.LFB2332:
	subq	$40, %rsp	 #,
	.seh_stackalloc	40
	.seh_endprologue
 # D:/RedPanda-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/11.2.0/include/c++/iostream:74:   static ios_base::Init __ioinit;
	leaq	_ZStL8__ioinit(%rip), %rcx	 #, tmp82
	call	_ZNSt8ios_base4InitC1Ev	 #
	leaq	__tcf_0(%rip), %rcx	 #, tmp83
 # D:/c++_school_work/e4/e4.cpp:20: }
	addq	$40, %rsp	 #,
 # D:/RedPanda-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/11.2.0/include/c++/iostream:74:   static ios_base::Init __ioinit;
	jmp	atexit	 #
	.seh_endproc
	.section	.ctors,"w"
	.align 8
	.quad	_GLOBAL__sub_I_main
.lcomm _ZStL8__ioinit,1,1
	.ident	"GCC: (x86_64-posix-seh-rev1, Built by MinGW-W64 project) 11.2.0"
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZNSirsERi;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x;	.scl	2;	.type	32;	.endef
	.def	_ZNSo3putEc;	.scl	2;	.type	32;	.endef
	.def	_ZNSo5flushEv;	.scl	2;	.type	32;	.endef
	.def	_ZNKSt5ctypeIcE13_M_widen_initEv;	.scl	2;	.type	32;	.endef
	.def	_ZSt16__throw_bad_castv;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	atexit;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr._ZSt4cout, "dr"
	.globl	.refptr._ZSt4cout
	.linkonce	discard
.refptr._ZSt4cout:
	.quad	_ZSt4cout
	.section	.rdata$.refptr._ZSt3cin, "dr"
	.globl	.refptr._ZSt3cin
	.linkonce	discard
.refptr._ZSt3cin:
	.quad	_ZSt3cin
