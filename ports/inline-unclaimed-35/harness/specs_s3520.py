"""specs_s3520.py - area 35 claim 20 (docs/20-unclaimed-35.md): 0x439760, ZInputAction::MakeActionExclusiveOwnerOfNodes(bool).

Stubbed: fake vtable of the object at this+0x15 with slot +0x4c (logs ecx only, returns 0) and slot +0x5c (writes a table
value through its pointer argument, returns a table value; the table index counts calls). The pointer argument is never
logged (it is a stack address). The manager object at P+0x11 holds a table at +0x1344 whose entries 10R+4 (R in 0..3) are
node chains; each node's first dword points to a V object (first dword 0 or nonzero; V = this+4 sometimes, which makes the
X == this branch run). The flag argument is random (its low byte picks the bl branches)."""
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


def _log_ecx_ret0(c):
    cells = c.emu.alloc(4, 4)
    c.emu.wbytes(cells, bytes(4))
    code = b'\x89\x0d' + ss.P(cells) + b'\xb8' + ss.P(0) + b'\xc2\x04\x00'   # mov [cells], ecx; mov eax, 0; ret 4
    return ss.code(c, code)


def _seq_stub(c, tabL, tabR):
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    tl = c.emu.alloc(4 * len(tabL), 4)
    c.emu.wbytes(tl, b''.join(ss.P(v) for v in tabL))
    tr = c.emu.alloc(4 * len(tabR), 4)
    c.emu.wbytes(tr, b''.join(ss.P(v) for v in tabR))
    code = (b'\x8b\x54\x24\x04'                        # mov edx, [esp+4]  (the pointer; not logged)
            + b'\xa1' + ss.P(cnt)                       # mov eax, [cnt]
            + b'\x8b\x0c\x85' + ss.P(tl)                # mov ecx, [tabL + eax*4]
            + b'\x89\x0a'                               # mov [edx], ecx
            + b'\x8b\x0c\x85' + ss.P(tr)                # mov ecx, [tabR + eax*4]
            + b'\xff\x05' + ss.P(cnt)                   # inc dword [cnt]
            + b'\x89\xc8'                               # mov eax, ecx
            + b'\xc2\x04\x00')                          # ret 4
    return ss.code(c, code)


def _walk(c):
    self_obj = _rnd(c, 0x200)
    c.emu.w32(self_obj + 4, 0)
    k = c.rng.randint(0, 2)
    tabL = ([1] * k + [0] * 8)[:8]
    tabR = [c.rng.randrange(4) for _ in range(8)]
    A = _rnd(c, 0x100)
    avt = c.emu.fake_vtable('ZWalkA', 0x100, {0x4c: _log_ecx_ret0(c), 0x5c: _seq_stub(c, tabL, tabR)})
    c.emu.w32(A, avt)
    c.emu.w32(self_obj + 0x15, A)
    M = _rnd(c, 0x1400)
    T = _rnd(c, 0x100)
    c.emu.w32(M + 0x1344, T)
    for R in range(4):
        n = c.rng.randint(0, 2)
        nodes = [_rnd(c, 0x100) for _ in range(n)]
        for i, nd in enumerate(nodes):
            r = c.rng.random()
            if r < 0.35:
                V = self_obj + 4
            else:
                V = _rnd(c, 0x100)
                if r < 0.7:
                    c.emu.w32(V, 0)
                else:
                    c.emu.w32(V, c.rng.getrandbits(32) | 1)
            c.emu.w32(nd, V)
            c.emu.w32(nd + 5, nodes[i + 1] if i + 1 < n else 0)
        c.emu.w32(T + 10 * R + 4, nodes[0] if n else 0)
    Pobj = _rnd(c, 0x100)
    c.emu.w32(Pobj + 0x11, M)
    if c.rng.random() < 0.5:
        B = Pobj + 4
        c.emu.w32(B, 3)
    else:
        B = _rnd(c, 0x100)
        c.emu.w32(B, 1)
        c.emu.w32(B + 8, Pobj + 4)
    c.emu.w32(self_obj + 0xc, B)
    return [self_obj, c.rng.getrandbits(32)]


S(0x439760, 'ZInputAction::MakeActionExclusiveOwnerOfNodes(bool) (vtable-map name) thiscall', 'thiscall', None,
  ret=None, gen=_walk,
  note='area 35 claim 20; slots +0x4c and +0x5c of this+0x15 hooked (ptr arg not logged); list walk and bl branches')
