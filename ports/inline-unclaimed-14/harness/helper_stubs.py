"""helper_stubs.py - shared callee stubs for unclaimed-14 (slice 13 heavy list).

A heavy function calls helpers that are not lifted. The PC code and the port both call the same helper address, so the
helper is replaced in the emulator image by a stub (serial_stubs.patch: `mov eax, stub; jmp eax`). The stub does no work;
it accumulates a checksum of ecx, edx and its stack arguments, and counts calls. Equal checksums and counts mean the port
passed the same register and stack values in the same calls. The helper's own output buffers are NOT written by the stub
(GUESS: the callee's effects are not modelled), so a function whose result depends on a helper's out-parameter is only
checked for the calls it makes, not for the value it computes from them. Say so in the write-up.

Usage in a spec gen: `hs.install(c, {0x4e0a10: (0, False, False), 0x4db2c0: (2, False, False), 0x4e0980: 0})`. Call it once
per case. The tuple form (count, use_ecx, use_edx) leaves out a register that holds a stack-local pointer or is not an argument.
Stub ABI: fastcall/thiscall-style register arguments are ignored by the pop count; `ret 4*nargs` pops the stack ones.
"""
import os
import struct
import sys

_HERE = os.path.dirname(os.path.abspath(__file__))
# shared-harness lives at <repo>/decomp-pilot/shared-harness. FF_RE_ROOT (set by pilot.py) finds it from any copy of this
# folder; the relative path works for the folder in place.
_CANDIDATES = [os.path.join(os.environ.get('FF_RE_ROOT', ''), 'decomp-pilot', 'shared-harness'),
               os.path.join(_HERE, '..', '..', 'shared-harness')]
for _SHARED in _CANDIDATES:
    if os.path.isfile(os.path.join(_SHARED, 'serial_stubs.py')):
        if _SHARED not in sys.path:
            sys.path.insert(0, _SHARED)
        break
import serial_stubs as ss  # noqa: E402

P = lambda v: struct.pack('<I', v & 0xffffffff)


def acc_stub(c, nargs, use_ecx=True, use_edx=True):
    """Accumulates the register arguments that are heap or object pointers (use_ecx, use_edx) and the stack arguments
    (nargs dwords) into acc; counts calls in cnt. Returns eax = 0. A register that holds a pointer to the caller's stack
    locals must be left out: the PC and the port have different stack addresses. A register a thiscall helper does not
    take must be left out too (its value is leftover garbage)."""
    cnt = c.emu.alloc(4, 4)
    acc = c.emu.alloc(16, 4)
    c.emu.w32(cnt, 0)
    for i in range(4):
        c.emu.w32(acc + 4 * i, 0)
    b = b''
    if use_ecx:
        b += b'\x01\x0d' + P(acc)         # add [acc], ecx
    if use_edx:
        b += b'\x01\x15' + P(acc + 4)     # add [acc+4], edx
    if nargs >= 1:
        b += b'\x8b\x44\x24\x04' + b'\x01\x05' + P(acc + 8)   # mov eax,[esp+4]; add [acc+8], eax
    if nargs >= 2:
        b += b'\x8b\x44\x24\x08' + b'\x01\x05' + P(acc + 12)  # mov eax,[esp+8]; add [acc+12], eax
    b += b'\xff\x05' + P(cnt)             # inc dword [cnt]
    b += b'\x31\xc0'                      # xor eax, eax
    b += b'\xc2' + struct.pack('<H', 4 * nargs)
    return ss.code(c, b), cnt, acc


def install(c, table):
    """Patches each helper address in table with an accumulating stub. The value is the stack argument count, or a tuple
    (count, use_ecx, use_edx). Returns a dict address -> (cnt, acc)."""
    out = {}
    for addr, v in table.items():
        nargs, use_ecx, use_edx = v if isinstance(v, tuple) else (v, True, True)
        stub, cnt, acc = acc_stub(c, nargs, use_ecx, use_edx)
        ss.patch(c, addr, stub)
        out[addr] = (cnt, acc)
    return out


def stub(c, nargs, ecx=True, edx=True, mask=None, writes=(), ret=0, cleanup=True):
    """General accumulating stub, for a helper or a vtable slot.

    nargs: stack argument count (the stub pops 4*nargs).
    ecx, edx: include that register in the checksum (only for heap or object pointers; never a stack local).
    mask: iterable of 1-based stack argument numbers to include in the checksum (default: all). Leave out a stack local.
    writes: iterable of (k, off, imm): writes dword imm at [arg_k + off] (k is 1-based; off < 128).
    ret: value returned in eax.
    Returns (stub_address, cnt, acc) where acc holds [ecx sum, edx sum, arg1 sum, ..., argN sum] and cnt the call count.
    """
    inc = set(range(1, nargs + 1)) if mask is None else set(mask)
    cnt = c.emu.alloc(4, 4)
    acc = c.emu.alloc(4 * (2 + nargs), 4)
    c.emu.w32(cnt, 0)
    for i in range(2 + nargs):
        c.emu.w32(acc + 4 * i, 0)
    b = b''
    if ecx:
        b += b'\x01\x0d' + P(acc)           # add [acc], ecx
    if edx:
        b += b'\x01\x15' + P(acc + 4)       # add [acc+4], edx
    for k in range(1, nargs + 1):
        if k in inc:
            b += b'\x8b\x44\x24' + bytes([4 * k]) + b'\x01\x05' + P(acc + 4 * (1 + k))  # mov eax,[esp+4k]; add [acc+4(1+k)],eax
    for k, off, imm in writes:
        b += b'\x8b\x44\x24' + bytes([4 * k]) + b'\xc7\x40' + bytes([off]) + P(imm)     # mov eax,[esp+4k]; mov dword [eax+off],imm
    b += b'\xff\x05' + P(cnt)               # inc dword [cnt]
    b += b'\xb8' + P(ret)                   # mov eax, ret
    if cleanup:
        b += b'\xc2' + struct.pack('<H', 4 * nargs)   # callee pops its stack arguments
    else:
        b += b'\xc3'                                   # caller pops them (PC does add esp, N after the call)
    return ss.code(c, b), cnt, acc
