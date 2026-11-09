# Defect classes that a differential pilot can miss

A port in `ports/` is checked by running the original function and the port on the same random inputs and comparing the return value, the memory
writes and faults. That proves the port agrees with the original *as the spec models it*. It says little about how the port behaves when it is called by
other code, and nothing about the places where the spec replaced a callee with a stub. Issue #1 reported 51 ports that were exact on both seeds and
still crashed the game; the same classes also showed up when ports were run inside the real executable. This page lists the classes, how to find each
one in the original, one example address per class, and what the spec has to do so the pilot can see it.

The stub-level classes (1-5) are what `tooling/strict` detects (see `tooling/STRICT.md`); classes 6-10 are not call-boundary defects and need a better
spec or a source review. Addresses are the ones in `ports/`; the numbers are checked against the disassembly of the original executable.

## How to read the original

For any callee: `ret N` at its exits gives the pop (N/4 words; plain `ret` is 0 or a cdecl callee), and the first uses of ECX and EDX before a write tell
whether it takes `this` (thiscall) or two register arguments (fastcall). For a virtual slot, take the vtable of the object's class and read the slot's
target. For any call site: the dwords pushed since the previous call or jump target are the candidate arguments, `add esp,N` after the call means the
callee did not pop them (cdecl), and ECX/EDX set in that chain are inputs. The word count of a callee decides which pushes belong to it; words pushed
before an earlier call and not popped by it are still pending and belong to a later call.

## 1. Callee convention declared wrong

Definition: the port's declaration of an exe function (stdcall, cdecl, thiscall, fastcall) differs from what that function does, so the call passes
`this` on the stack, or the argument in ECX, or pops the wrong number of words.
Detect: callee `ret N` plus ECX/EDX reads; a cdecl callee is followed by `add esp,N` at every site.
Example: `0x5d57c0`: the callee `0x45c510` is cdecl with one argument (`push esi; call; add esp,4`), the port declared it with the argument in ECX.
Spec change: declare the stub with the callee's real convention and pop; a stub that reads ECX/EDX must read them from the registers, and its recorder
must write ECX/EDX junk after returning, as the real callee clobbers them.

## 2. `this` missing or wrong, including the `/GS` cookie check

Definition: a thiscall callee is called without ECX, with a stale ECX, or with the wrong pointer (for example `z+8` where the original passes `[z+8]`).
The most frequent instance is the stack-cookie check (`__security_check_cookie`, `0x633654`), which takes the cookie xor frame pointer in ECX; ports
called it as `ext_633654(0)`. About 102 functions in 12 folders share this shape.
Detect: the callee reads ECX before writing it; at the site, ECX is set in the chain before the call.
Example: `0x420ea0` (cookie check without ECX); `0x46f2d0` (wrong `this`).
Spec change: the stub must read ECX and the spec must supply the value the original supplies; with the real cookie check, compute ECX from the frame.

## 3. Wrong number of argument words, including words left by an earlier call

Definition: the port passes fewer or more words than the callee pops, often because a push before one call is really the first argument of the next
call (the earlier callee pops fewer words than were pushed). Typical sites are the render-manager slots (one slot pops four words, a neighbouring one
pops one) whose surplus pushes become the trailing arguments of the next widget slot.
Detect: balance the stack across the whole chain: pushes minus the earlier callee's `ret N` equals what the next call receives.
Example: `0x5f0d30`: one word (the entry ECX) is the argument of the first slot (pops 1), five words go in front of the second slot (pops 4, one stays
pending), and the next slot receives that pending word plus two more, three in total. A split that passes the wrong word to the first slot and four to
the last also balances the stack, which is why the pilot accepted it. Also `0x4ca820`, `0x4f9c00`.
Spec change: give each fake slot the arity read from its vtable target, not the arity that makes the port's stack balance, and compare the argument
words, not only the pop.

## 4. Argument order reversed or value wrong

Definition: the right number of arguments in the wrong order, or a constant that is not the original's.
Detect: compare pushes at the site, last push is the first argument.
Example: `0x4cd180`: the delete call receives (pointer, 8) in the original, the port passed (8, pointer).
Spec change: the stub has to log its arguments and the pilot must compare the log with the original's; a stub that only counts calls cannot see it.

## 5. Tail jump turned into a call (or the reverse)

Definition: the original ends in `jmp callee` (the callee returns for the function, with the function's own pop count), the port calls and returns.
The stack is off by the callee's frame unless the pop counts agree, and the callee sees a different return address.
Detect: the original's last instruction before the epilogue is a jump out of the function.
Example: `0x565a30`. Note that an optimising compiler may turn the port's call back into a tail jump, so the difference only shows in a build without
sibling-call optimisation.
Spec change: build the pilot with `-fno-optimize-sibling-calls` for the function and record call-versus-jump in the stub log.

## 6. Local variable too small

Definition: the original keeps a 12-byte iterator (three words) in its frame where the port has a 4- or 8-byte local; callee slots that write 12 bytes
overwrite the neighbouring locals.
Detect: the frame offsets of the arguments passed to the same callee differ by 12 or more; the callee writes through the pointer.
Example: `0x4b4040`.
Spec change: the fake slots in the spec must write the full 12 bytes and the spec must compare the neighbouring locals.

## 7. By-value object truncated

Definition: a `std::basic_string` or similar passed by value occupies several stack words in the original; the port passed `&local` or the first word.
Detect: the callee's `ret N` is larger than one word and several consecutive pushes precede the call.
Example: `0x602a60`.
Spec change: the stub records every word of the object.

## 8. Return value width

Definition (two directions). Narrow port, wide original: the original leaves 0 or 1 zero-extended in the full EAX (`xor eax,eax; ...; setcc al`), the port
returns `bool` or `u8`, and the spec compares only AL (`ret='al'`). Void port, value consumed: the original returns a callee's EAX and a caller reads
it, while the port is declared `void`.
Detect: look at the last write to EAX before `ret` and at what the callers read after the call.
Example: `0x4d5120` (nativeEof, signed compare, zero-extended); `0x656f20` (void port with five callers reading EAX).
Spec change: compare the full EAX (`ret='eax'`) whenever the original's callers may read more than AL, and declare the port's return type to match.

## 9. Large frame without a stack probe

Definition: the original reserves more than a page of locals with a plain `sub esp` (no probe); a port compiled with probes behaves differently on
the guard page and in frame layout.
Detect: `sub esp,imm` above 0x1000 with no `__chkstk` call.
Example: `0x4d6520` (a file-search function that reserves a 0x3006c-byte frame).
Spec change: none for the checker; build flags decide whether the port probes.

## 10. A spec that compares nothing

Definition: the spec checks the return and the memory writes, but the original faults on every case or the return register is not the one the port
sets, so "exact" means "both sides did nothing comparable".
Detect: the result has every case faulting or an all-equal trivial output.
Example: `0x445c50` (the port returned `void`, the original is thiscall and returns EAX).
Spec change: make at least a few cases exercise the path and compare EAX.

## What the checker still cannot see

Classes 6-10 are not detected by strict stubs and need a corrected spec or a source review. Even for classes 1-5 only the paths the random cases execute
are checked, and the pop of a fake slot cannot be derived from its call site alone. `strict-exact` is a stronger result than `exact`, not a proof.
