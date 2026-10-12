"""specs_s2427.py - decomp area 24, batch 2427.
0x61bc30 (GUESS owner), cdecl, plain ret, eax: the object (first stack argument) gets its slot 0x14 with the second and
third stack arguments; the slot is a recorder returning a random dword.
0x435e70 ZInputDeviceGameControlBase::IsConnected(int), thiscall, ret 4, float on st0: when the index is at most the count
at +0x61 (signed), the float at this + 0x1d + 4*index is returned, otherwise 0.0. Indices are 0..count+2 (non-negative,
so the reads stay inside the object)."""
from pilot import S
from recruits_util import rnd, pystub, obj, clear_hooks


def _fwd(c):
    clear_hooks(c)
    r = c.rng
    o = obj(c, 0x40, {0x14: pystub(c, 2, ret=lambda emu, k: r.getrandbits(32))})
    return [o, r.getrandbits(32), r.getrandbits(32)]


def _conn(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = rnd(c, 0x100)
    cnt = r.randint(0, 6)
    e.w32(o + 0x61, cnt)
    for k in range(10):
        e.wf32(o + 0x1d + 4 * k, r.uniform(-10.0, 10.0))
    return [o, r.randint(0, cnt + 2)]


S(0x61bc30, 'GUESS: cdecl forwarder to slot 0x14 (0x61bc30)', 'cdecl', None, ret='eax', gen=_fwd, note='batch2427')
S(0x435e70, 'ZInputDeviceGameControlBase::IsConnected', 'thiscall', None, ret='st0', gen=_conn, note='batch2427')
