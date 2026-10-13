"""specs_s77.py - unclaimed-68 batch 77 (slice 7). Names GUESS (FUN_addr). The CRT sized delete 0x634273 (cdecl) and 0x54f870
(thiscall, ret 8) are hooked and logged; exe 0x4da1d0 and the recursion 0x5fb330 run as they are. The node list is acyclic: each node's
next pointer names a later node, and its child pointer (+9) names an earlier one or 0, so the recursion terminates."""
from pilot import S
from engine_stubs import zero_obj


def _setup(c):
    c.emu.hook(0x634273, lambda em, r: (em.calllog.append(('delete634273', em.arg32(0), em.arg32(1))), em.ret(eax=0, argbytes=0)))
    c.emu.hook(0x54f870, lambda em, r: (em.calllog.append(('f54f870', em.reg('ecx'), em.arg32(0), em.arg32(1))), em.ret(eax=0, argbytes=8)))


def _rnd(c, n):
    o = zero_obj(c, n)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return o


def _g43df70(c):
    o = _rnd(c, 0x40)
    obj = zero_obj(c, 0x100)
    c.emu.wbytes(obj, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    c.emu.w32(obj + 0x54, 0)
    c.emu.w32(o + 8, obj)
    return [o]


def _g4d4d30(c):
    return [_rnd(c, 0x40), c.rng.getrandbits(32)]


def _g5fb330(c):
    k = c.rng.randrange(0, 5)
    nodes = [zero_obj(c, 0x20) for _ in range(k)]
    for i, n in enumerate(nodes):
        c.emu.wbytes(n, bytes(c.rng.getrandbits(8) for _ in range(0x20)))
        nxt = nodes[i + 1] if i + 1 < k and c.rng.random() < 0.8 else 0
        child = nodes[c.rng.randrange(0, i)] if i > 0 and c.rng.random() < 0.5 else 0
        c.emu.w32(n + 5, nxt)
        c.emu.w32(n + 9, child)
    self_o = _rnd(c, 0x40)
    head = nodes[0] if nodes else 0
    return [self_o, head]


S(0x4d4d30, 'FUN_4d4d30 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_g4d4d30, setup=_setup,
  note='unclaimed-68 batch 77: vt = 0x696634; delete(this, 9) when flags & 1')
