/* func_0038DBA0 (PAL frontbin, src/frontbin/38DBA0.c, flags -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack
   -mno-check-zero-division @ps2as). Near miss, 2026-11-21. Retail keeps the difference in $f0 and
   pi in $f14 and has a lone nop after `mtc1 $at, $f14` and unfilled delay slots after `c.lt.s`
   and `jr`. Plain C gives 13 to 19 diff with the file's flags (five wordings, the best below):
   gcc puts pi in $f0, the difference in $f12, and fills the delay slots. The US draft
   (rac3-uya-decomp func_00389468, commit 13cf5c5) checks MATCH with the file's flags, but only
   with register pins (`register float x __asm__("$f0")`) and `__asm__ volatile(".word 0")` for the
   nop, which AGENTS.md does not allow in matched C; boot_elf's twin func_0038DF80
   (src/boot_elf/text/38DF80.c) is that form. The unfilled slots may mean it was hand-written. */
float func_0038DBA0(float first, float second) {
    float d = __builtin_fabsf(first - second);
    float pi = 3.1415927f;
    if (d < pi) return d;
    return (pi + pi) - d;
}
