"""specs_s6309.py - unclaimed-63 batch 9 (docs/20-unclaimed-63.md): ZGROUP::DuplicateToResource (0x440220), thiscall with five stack
arguments (ret 0x14). Stubs, rewritten each case (with a flush):
  * 0x45df10 (original, ss.patch): records ECX and its five stack arguments into rings, returns R (a random object);
  * the list at this+0x50 has 0 to 3 nodes; node+0x54 is a random object (never null), node+0x60 the next node;
  * each node's object has a vtable slot +0x1c0 that records ECX and its five stack arguments into rings and returns 0;
    the object's +4 is a random pointer or 0 (choosing the default constant 0x67c8e8 in the other case).
The flag is 0 or nonzero, so the list loop runs in about half the cases."""
from pilot import S
import sys, os
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _cell(c, n=1):
    a = c.emu.alloc(4 * n, 4)
    c.emu.wbytes(a, bytes(4 * n))
    return a


def _le(v):
    return v.to_bytes(4, 'little')


def _flush(c):
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _stub(c, code):
    s = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(s, code)
    _flush(c)
    return s


def _record5(cnt, rings, ecx_ring, ret_code):
    """Records ECX and the five stack arguments into rings indexed by the call count, then bumps the count.
    edx = count; ring_j[edx] = arg_j (j = 1..5, at [esp+4+4(j-1)]); ring_ecx[edx] = ecx; count++; then ret_code."""
    code = b'\x8b\x15' + _le(cnt)                                  # mov edx, [cnt]
    code += b'\x89\x0c\x95' + _le(ecx_ring)                         # mov [ecx_ring + edx*4], ecx
    for j, ring in enumerate(rings):
        code += bytes([0x8b, 0x44, 0x24, 4 + 4 * j]) + b'\x89\x04\x95' + _le(ring)   # mov eax,[esp+..]; mov [ring+edx*4],eax
    code += b'\xff\x05' + _le(cnt)                                  # inc dword [cnt]
    return code + ret_code


def _rings(c):
    cnt = _cell(c)
    rings = [_cell(c, 4) for _ in range(5)]
    ecx_ring = _cell(c, 4)
    return cnt, rings, ecx_ring


def _gen(c):
    self_ = _rnd(c, 0x100)
    p = [c.rng.getrandbits(32) for _ in range(4)]
    cnt, rings, ecx_ring = _rings(c)
    R = _rnd(c, 0x80)
    ss.patch(c, 0x45df10, _stub(c, _record5(cnt, rings, ecx_ring, b'\xb8' + _le(R) + b'\xc2\x14\x00')))
    _flush(c)
    # the list objects share one vtable (slot +0x1c0 records the five arguments)
    cnt2, rings2, ecx2 = _rings(c)
    vt = c.emu.alloc(0x800, 4)
    c.emu.w32(vt + 0x1c0, _stub(c, _record5(cnt2, rings2, ecx2, b'\x31\xc0' + b'\xc2\x14\x00')))
    nnodes = c.rng.randint(0, 3)
    nodes = [_rnd(c, 0x80) for _ in range(nnodes)]
    for i, nd in enumerate(nodes):
        q = _rnd(c, 0x40)
        c.emu.w32(q, vt)
        c.emu.w32(q + 4, c.rng.choice([0, c.rng.getrandbits(32) | 4]))
        c.emu.w32(nd + 0x54, q)
        c.emu.w32(nd + 0x60, nodes[i + 1] if i + 1 < nnodes else 0)
    c.emu.w32(self_ + 0x50, nodes[0] if nodes else 0)
    flag = c.rng.choice([0, 1, 0x80, c.rng.getrandbits(8)])
    return [self_, p[0], p[1], p[2], p[3], flag]


S(0x440220, 'ZGROUP::DuplicateToResource (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-63 batch 9; 0x45df10 stubbed; list objects vtbl+0x1c0 stub; rings record args')
