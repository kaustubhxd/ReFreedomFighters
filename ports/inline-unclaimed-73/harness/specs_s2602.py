"""specs_s2602.py - area 73 batch 2 (residue 12): ZRepositionCharacter::Load (0x5c4240).
The load object is a fake vtable. Its slot +0x40 writes a value through its pointer argument. The argument is a heap
address (this+0x4c) or a stack address (the argument slot); the handler logs only heap arguments, because stack addresses
differ between the exe and the port. Slot +0x70 logs its argument. The render-control object (g_sys+0x9b) has slot +0x58
(logged, returns a random dword)."""
from pilot import S
from pe_emu import HEAP_BASE


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _reposition(c):
    e = c.emu
    self_o = _rnd(c, 0x100)
    v_heap = c.rng.getrandbits(32)
    v_slot = c.rng.getrandbits(32)

    def w40(em, r):
        p = em.arg32(0)
        if HEAP_BASE <= p < HEAP_BASE + 0x1000000:
            em.calllog.append(('zrepos', 0x40, em.reg('ecx'), (p,)))
            em.w32(p, v_heap)
        else:
            em.calllog.append(('zrepos', 0x40, em.reg('ecx'), ('stack-slot',)))
            em.w32(p, v_slot)
        em.ret(eax=0, argbytes=4)

    def h70(em, r):
        em.calllog.append(('zrepos', 0x70, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    load = _rnd(c, 0x100)
    e.w32(load, e.fake_vtable('zloadgame_rep', 0x80 // 4, {0x40: w40, 0x70: h70}))

    ctl = _rnd(c, 0x100)
    e.w32(ctl, e.logging_vtable('rendctl', 0x60 // 4, impl={0x58: lambda em, a: (c.rng.getrandbits(32), None)},
                                argwords={0x58: 1}))
    sys = _rnd(c, 0x200)
    e.w32(sys + 0x9b, ctl)
    e.w32(0x70039c, sys)
    return [self_o, load]


S(0x5c4240, 'ZRepositionCharacter::Load (unknown) thiscall', 'thiscall', None, ret='al', gen=_reposition,
  note='area 73 batch 2; slot +0x70(this+0x48); +0x40 into this+0x4c and into the arg slot; ctl +0x58 -> this+0x50')
