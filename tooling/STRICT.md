# Strict callee stubs (`FF_STRICT_STUBS=1`)

Issue #1 pointed out a gap in the checker: the callee stubs in a spec took the calling convention and the number of argument words from the port's own
declaration, ignored ECX/EDX on entry, and left ECX/EDX untouched on return. A port that calls an exe function with the wrong convention, the wrong
`this`, a missing word or a reversed argument order could therefore still be "exact". The strict mode closes that gap for the call boundary.

It does not replace `pilot.py` or `pe_emu.py`. `tooling/strict/pilot_strict.py` is a launcher that patches the stub machinery at run time. Without
`FF_STRICT_STUBS=1` it behaves exactly like `pilot.py`.

## What it does

The truth comes from the original executable (capstone over the pristine executable that `pe_emu.py` loads, `DEFAULT_EXE` there; nothing is executed), never from a spec or a port
(`tooling/strict/strict_truth.py`):

* per direct callee: its pop (`ret N`, thunks and tail jumps followed), which of ECX/EDX it reads before writing (may-read dataflow over its CFG, calls
  followed to depth 3; `push ecx` is ignored as the 4-byte reserve idiom) and which it writes (so it does not preserve them);
* per call site in the original (needed for fake vtable slots, function pointers and imports, which have no address): `add esp,N` or `pop ecx` after the
  call means cdecl with N/4 words; otherwise the dwords pushed in the chain before the call. ECX is an input when the chain sets it.

At every call into a stub, in the original run and in the port run:

1. ECX/EDX (when the callee reads them), the argument words and call-versus-tail-jump are logged. The two logs are compared entry by entry. Stack
   addresses and pointers into the exe image or the port blob are tokens, because they differ between the two runs by construction.
2. After the stub returns, ECX and EDX (those the real callee writes; both for fake slots) are overwritten with junk (`0xe1c0xxxx`) in both runs. A port
   that relied on a register surviving a call now diverges.
3. The pop is the original's `ret N` (direct callees and call sites with a clean stack), whatever the spec's handler passes to `emu.ret()`.

When a case mismatches, the result row also carries `baseline` (the same function with strict off), `orig_stable` (whether the ORIGINAL behaves the same
with and without strict; when it does not, the checker is the suspect, not the port) and `strict_notes` (spec stub declarations that contradict the
original's call site).

`FF_STRICT_SITE_CONTRACTS` can name a JSON file with explicit, hash- and call-byte-checked argument counts for individual call sites. That is not
inference from the original; its use is listed in `strict_notes`, and it needs support from other evidence.

## How to run

You need `FF_RE_ROOT` (a directory whose `bin/` holds your own copy of the original executable under the name `pe_emu.py` expects), Python with
`unicorn`, `capstone` and `pefile`, and a C++ toolchain for `tooling/build.sh`. The strict mode uses the corrected harness (`pe_emu.TEB = 0x7f000000`).

```
export FF_RE_ROOT=/path/to/root
# one function, strict, like pilot.py with the launcher in front
PILOT_SPECS=ports/<folder>/harness PILOT_BUILD=<dir> FF_STRICT_STUBS=1 \
    python3 tooling/strict/pilot_strict.py tooling/pilot.py <addr> -n 1000 --seed 1

# a prepared, built work copy of one folder (the ports are only read)
python3 tooling/strict/prep.py <folder>

# the whole published set: map functions to folders, run seed 1, then seed 2 on the exact ones, classify
python3 tooling/strict/mk_map.py
python3 tooling/strict/run_full.py 1 -j 4
python3 tooling/strict/run_full.py 2 -j 4
python3 tooling/strict/classify.py full --write        # writes reverify-strict.tsv and classes.json under the output directory
python3 tooling/progress_tiers.py                       # tier counts, T3 = strict-exact
```

Output goes to `$FF_STRICT_OUT` (default `tooling/strict/out/`) and built copies to `$FF_STRICT_WORK` (default `tooling/strict/work/`, git-ignored).
`run_full.py` is resumable: a chunk whose result file exists is skipped. Several folders need a good deal of RAM and time; seed 2 of some folders ran
for hours in our runs (see below), so use a per-run timeout.

## Regression corpus: `selftest.py`

`selftest_corpus_src.tsv` lists 62 ports that were defective when they were found: the 51 of issue #1, the 21 of `known.tsv` (they must all be in
the corpus) and further confirmed-bad ports. `python3 tooling/strict/selftest.py calibrate` runs every row through every detector and records which one
caught it; `check` re-runs the rows and fails when a previously caught row is no longer caught (a lost detection). Rows that no detector catches are
listed as BLIND, never silently passed. The corpus names ports as they were DEFECTIVE: once a defect is fixed in `ports/` the row stops being
detected, so point `FF_PORTS` at a checkout from before the fixes. Detectors: strict launcher seed 1, a corrected-spec run (needs an overlay directory,
`FF_STRICT_OVERLAYS`; skipped when absent), a no-argument-logging run, an EAX-observing synthetic target, and the strict launcher on seed 2.

Measured with `FF_PORTS` pointing at the published ports from before any of these fixes (no overlays, 300 cases): 23 of the 62 rows are caught
(22 by the strict launcher on seed 1, one more on seed 2) and 39 are BLIND. The BLIND rows are defects that are not at a call boundary (see below), paths
the random cases never reach, rows whose corpus entry names an address where no defect was ever confirmed, and rows that need an overlay with a
corrected spec, which is not published; `calibrate` lists them instead of passing them. On the 21 known-bad ports of the first validation (with
corrected-spec overlays available), the strict launcher alone caught 14. The other 7 are not call-boundary defects (a local that is too
small, upper bits of a bool, a truncated by-value argument, a clang tail-call merge, a path the random cases never reach); those need a corrected
spec, not stricter stubs.

## Measured results (full re-run, 2026-10-28 to 2026-11-02)

Scope: 12,978 functions were listed as verified on both seeds when the re-run started. 12,360 of them could be mapped to a folder holding both a
spec row and a built port; **618 could not be mapped and were not re-checked**. Result on the 12,360:

| class | functions | share |
|---|---|---|
| strict-exact (exact on seeds 1 and 2, 0 faulting) | **10,744** | **86.9%** |
| missing-this/ecx | 328 | 2.7% |
| harness-error (load crashes: missing helper modules, spec load errors; not strict findings) | 299 | 2.4% |
| tail-jump | 197 | 1.6% |
| seed2-incomplete (exact on seed 1; the seed-2 run never finished) | 194 | 1.6% |
| wrong-arg-count | 170 | 1.4% |
| wrong-arg-value | 136 | 1.1% |
| baseline-fail (also fails with strict off) | 96 | 0.8% |
| strict-unsupported (non-PEEmu pilots, refused rather than run without strict stubs) | 79 | 0.6% |
| call-sequence | 72 | 0.6% |
| unknown | 19 | 0.2% |
| missing-edx | 13 | 0.1% |
| orig-junk-sensitive | 12 | 0.1% |
| wrong-arg-order | 1 | 0.0% |

So 10,744 functions are strict-exact and **1,616 are not**. Do not read the failing classes as defect counts. We reviewed samples of 20 per message
class against the original's disassembly:

| first strict message | failures | sampled | false positives |
|---|---|---|---|
| ECX differs where the callee reads ECX | 298 | 20 | 60% |
| same, native callee | 7 | 7 | 71% |
| EDX differs | 9 | 9 | 22% |
| EDX, native callee | 4 | 4 | 0% |
| argument words differ | 246 | 20 | 85% |
| same, native callee | 66 | 20 | 80% |
| reversed arguments | 1 | 1 | 0% |
| original tail-jumps, port calls | 195 | 20 | 100% |
| call sequence differs | 65 | 20 | 100% |
| junk changes the ordinary comparison | 111 | 20 | 90% |

Typical false-positive causes: ECX used only as a vtable fetch or scratch at a virtual-slot call; a callee that reads only CL or a low byte of an
argument; an argument count over-estimated from a shared `add esp,N` cleanup or from the pushes of the next call; tail jumps from exception-handler
funclets; a CRT `sqrt` inlined as `sqrtsd`; the `/GS` cookie check not modelled; an elided `memset`.

Defects confirmed in the samples: the `/GS` cookie check called without ECX (about 102 functions, one function-level class), callees declared with the
wrong calling convention (thiscall or fastcall callee declared stdcall or cdecl), a wrong `this` value, a reversed argument order, a missing pushed word
before a slot call, and native callees that take words left on the stack by an earlier call but are declared without stack arguments.

## Limits

* `strict-exact` is not a proof of correctness. Defects outside call boundaries are invisible: locals that are too small, upper bits of a bool, a
  truncated by-value argument, clang merging a call into a tail jump (the reverse, original tail jump and port call, is reported).
* The pop of a fake virtual slot, function pointer or import cannot be derived from its call site: words pushed before an earlier call may be arguments
  of a later one. For those the spec's declaration stays; only an `add esp,N` after the call is trusted, and the argument words compared are the pushes
  since the last call, a lower bound.
* Partial-width reads (CL/DL, low-byte arguments), shared cleanups, funclet tail jumps and call-sequence differences from inlined library code are not
  modelled; they are the main false-positive sources above.
* Only paths the spec's random cases execute are checked.
* Native (non-stubbed) callees get the entry checks but no junk, because link-time-optimised code can legitimately rely on callee-preserved registers.
* 194 functions (the `inline-herocombat` folders) are exact on seed 1 and have no completed seed-2 result: the strict run ran for many hours without
  finishing, which points at a runaway loop that needs a per-case instruction cap in the launcher. They are not counted as passes.
* 618 functions could not be mapped to a folder and were never re-checked; 79 use a pilot that is not a PEEmu pilot and are unsupported.
* Results before the corrected harness (`TEB = 0x7f000000`) were produced with the fake TEB at address 0.
