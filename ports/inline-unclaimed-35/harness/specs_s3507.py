"""specs_s3507.py - area 35 claim 7 (docs/20-unclaimed-35.md): CAction::RunMultiple (0x4a19a0).

Stubbed (unverified, not lifted):
- The object at this+0x44 has a vtable whose slot +0x128 is a three-argument writer (ret 12): it logs its three arguments and
  writes, through its second argument (a heap pointer, this+0x102), either 0 or the address of a separate list L (50/50).
- The cdecl compare at the global function pointer 0x676414 is a code stub that logs its two arguments and returns a per-case
  value (0 means "matches"). Its arguments are heap values (this+0x7a and an entry's +0x7a), so they are logged.
- The entries' slot +0x90 is logged (one argument, ret 4).
- The hook at 0x7003b0 is null; the global u16 at 0x7002ac is random.
The actor (this) is 0x1000 random bytes: this+0x102 is 0 or the list L (the call is skipped when it is set); this+0x7a random, the inline list at this+0x7e (count 0..4, entries at +0x82).
L is a 0x40-byte list (count 0..4, entries at +4). Entries are 0x100-byte objects with a logged vtable and a random +0x7a."""
import os
import struct
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss   # noqa: E402

from pilot import S   # noqa: E402


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _cells(c, n):
    a = c.emu.alloc(4 * n, 4)
    c.emu.wbytes(a, bytes(4 * n))
    return a


def _writer3(c, value, cells):
    """thiscall, three arguments: logs them into cells[0..2], writes value through arg1, ret 12."""
    code = (b'\x8b\x44\x24\x04' + b'\xa3' + ss.P(cells)
            + b'\x8b\x44\x24\x08' + b'\xa3' + ss.P(cells + 4)
            + b'\x8b\x44\x24\x0c' + b'\xa3' + ss.P(cells + 8)
            + b'\x8b\x54\x24\x08'                             # mov edx, [esp+8]  (arg1: pointer)
            + b'\xb9' + ss.P(value)                           # mov ecx, value
            + b'\x89\x0a'                                     # mov [edx], ecx
            + b'\xb8' + ss.P(0)                               # mov eax, 0
            + b'\xc2\x0c\x00')                                # ret 12
    return ss.code(c, code)


def _cmp_stub(c, cells, ret):
    """cdecl compare: logs arg0 and arg1 into cells[0..1], returns ret in eax, ret 0 (cdecl)."""
    code = (b'\x8b\x44\x24\x04' + b'\xa3' + ss.P(cells)
            + b'\x8b\x44\x24\x08' + b'\xa3' + ss.P(cells + 4)
            + b'\xb8' + ss.P(ret)
            + b'\xc3')
    return ss.code(c, code)


def _entry(c, vt):
    e = _rnd(c, 0x100)
    c.emu.w32(e, vt)
    c.emu.w32(e + 0x7a, c.rng.getrandbits(32))
    return e


def _run(c):
    self_obj = _rnd(c, 0x1000)
    ecells = _cells(c, 3)
    ccells = _cells(c, 2)
    evt = c.emu.logging_vtable('ZActionEntry', 0x40, impl={}, argwords={0x90: 1})
    entries = [_entry(c, evt) for _ in range(5)]
    k_this = c.rng.randrange(0, 5)
    c.emu.w32(self_obj + 0x7a, c.rng.getrandbits(32) if c.rng.random() < 0.5 else 0)
    c.emu.w32(self_obj + 0x7e, k_this)
    for i in range(k_this):
        c.emu.w32(self_obj + 0x82 + 4 * i, entries[c.rng.randrange(5)])
    L = _rnd(c, 0x40)
    k_l = c.rng.randrange(0, 5)
    c.emu.w32(L, k_l)
    for i in range(k_l):
        c.emu.w32(L + 4 + 4 * i, entries[c.rng.randrange(5)])
    value = 0 if c.rng.random() < 0.5 else L
    # The list pointer at this+0x102 is either zero (the slot +0x128 call runs) or already a list (the call is skipped).
    c.emu.w32(self_obj + 0x102, 0 if c.rng.random() < 0.5 else L)
    obj = _rnd(c, 0x200)
    ovt = c.emu.fake_vtable('ZActionObj', 0x140, {0x128: _writer3(c, value, ecells)})
    c.emu.w32(obj, ovt)
    c.emu.w32(self_obj + 0x44, obj)
    c.emu.w32(0x676414, _cmp_stub(c, ccells, c.rng.choice([0, 0, 1, c.rng.getrandbits(32)])))
    c.emu.w32(0x7003b0, 0)
    c.emu.wbytes(0x7002ac, bytes([c.rng.getrandbits(8), c.rng.getrandbits(8)]))
    return [self_obj, c.rng.getrandbits(32)]


S(0x4a19a0, 'CAction::RunMultiple (unknown) thiscall', 'thiscall', None, ret=None, gen=_run,
  note='area 35 claim 7; slot +0x128 writer (logged args); cdecl compare 0x676414 stub; entries slot +0x90 logged')
