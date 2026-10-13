"""specs_s1109.py - unclaimed-11 batch 9 (core-todo residue-10): ZRepositionCharacter::CopyData(ZEventBase*) at 0x5c40e0,
thiscall, ret 4. The body copies two dwords (+0x4c, +0x50) from the source; then, if the source object at +0x48 is set, it
calls the source object's slot 0x4c with an out pointer (tmp), and loops: while tmp is nonzero, it calls this object's
slot 0x04 with the last return value and then the source's slot 0x5c with the out pointer again.
The inner objects are serial_stubs.mkobj objects; slot 0x4c is a wr stub (writes a fixed value), slot 0x5c is a custom stub
that writes table[count & 7] through its out pointer and returns count + 100 (so the loop ends at a zero in the table),
and the destination's slot 0x04 is a rec stub (unverified callees, stubbed). The table always holds a zero."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S


def _seq_stub(c, cnt, tab):
    # thiscall, one argument (out pointer): *out = tab[cnt & 7]; cnt++; return cnt_old + 100. ret 4.
    b = (b'\x8b\x44\x24\x04'                       # mov eax, [esp+4]
         + b'\x8b\x0d' + ss.P(cnt)                 # mov ecx, [cnt]
         + b'\x89\xca'                             # mov edx, ecx
         + b'\x83\xe2\x07'                         # and edx, 7
         + b'\x8b\x14\x95' + ss.P(tab)             # mov edx, [tab + edx*4]
         + b'\x89\x10'                             # mov [eax], edx
         + b'\xff\x05' + ss.P(cnt)                 # inc dword [cnt]
         + b'\x8d\x41\x64'                         # lea eax, [ecx + 100]
         + b'\xc2\x04\x00')                        # ret 4
    return ss.code(c, b)


def _cd(c):
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    tab = c.emu.alloc(32, 4)
    vals = [c.rng.getrandbits(32) | 1 for _ in range(8)]
    vals[c.rng.randrange(8)] = 0
    c.emu.wbytes(tab, b''.join(struct.pack('<I', v) for v in vals))
    inner_src = ss.mkobj(c, {0x4c: ss.wr(c, 1, 0, 4, c.rng.getrandbits(32)), 0x5c: _seq_stub(c, cnt, tab)}, size=0x40)
    inner_dst = ss.mkobj(c, {0x04: ss.rec(c, 1, ret=0)}, size=0x40)
    src = ss.mkobj(c, {}, size=0x60)
    dst = ss.mkobj(c, {}, size=0x60)
    for o in (src, dst):
        c.emu.w32(o + 0x4c, c.rng.getrandbits(32))
        c.emu.w32(o + 0x50, c.rng.getrandbits(32))
    c.emu.w32(src + 0x48, inner_src if c.rng.random() < 0.8 else 0)
    c.emu.w32(dst + 0x48, inner_dst)
    return [dst, src]


S(0x5c40e0, 'ZRepositionCharacter::CopyData (unknown) thiscall', 'thiscall', None, ret=None, gen=_cd,
  note='unclaimed-11 batch 9 (residue 10); inner objects stubbed')
