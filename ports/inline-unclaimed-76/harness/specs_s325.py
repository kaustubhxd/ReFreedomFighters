"""specs_s325.py - gap band, batch 325: the two guard forwarders with their else paths.
Guard byte at a+0x18. 42abee (hooked, cdecl, three arguments) returns a per-run value. 0x602200 else: the engine global 0x70039c has a
vtable slot 0x190 (thiscall, returns the object r); r's vtable slot 0x194 is the tail target: a thiscall stub with four arguments that
logs ECX and the arguments and pops them, returning a per-run value. 0x602120 else: the global 0x724270 is an object whose vtable slot
0x10 is a cdecl stub (four arguments) returning a per-run value."""
from pilot import S


def _gen_for(which):
    def gen(c):
        e = c.emu
        rng = c.rng
        rv42 = rng.getrandbits(32)
        rvtail = rng.getrandbits(32)
        rv10 = rng.getrandbits(32)

        def h42(em, r):
            em.calllog.append(('h42abee', 0, None, tuple(em.arg32(k) for k in range(3))))
            em.ret(eax=rv42, argbytes=0)

        e.hook(0x42abee, h42)

        if which == 'a':
            def slot190(em, r):
                em.calllog.append(('slot190', 0x190, em.reg('ecx'), ()))
                em.ret(eax=robj, argbytes=0)

            def tail194(em, r):
                em.calllog.append(('tail194', 0x194, em.reg('ecx'), tuple(em.arg32(k) for k in range(4))))
                em.ret(eax=rvtail, argbytes=0)

            robj = e.alloc(0x40, 4)
            e.w32(robj, e.fake_vtable('robj325', 0x80, {0x194: tail194}))
            g = e.alloc(0x40, 4)
            e.w32(g, e.fake_vtable('g325', 0x200, {0x190: slot190}))
            e.w32(0x70039c, g)
        else:
            def slot10(em, r):
                em.calllog.append(('slot10', 0x10, None, tuple(em.arg32(k) for k in range(4))))
                em.ret(eax=rv10, argbytes=0)

            robj = e.alloc(0x40, 4)
            e.w32(robj, e.fake_vtable('r325', 0x40, {0x10: slot10}))
            e.w32(0x724270, robj)

        a = e.alloc(0x40, 4)
        e.wbytes(a, bytes(rng.getrandbits(8) for _ in range(0x40)))
        e.wbytes(a + 0x18, bytes([rng.choice([0, 0, 1])]))
        return [a, rng.getrandbits(32), rng.getrandbits(32), rng.getrandbits(32)]
    return gen


S(0x602200, 'guard602200 (GUESS)', 'cdecl', None, ret='eax', gen=_gen_for('a'), note='batch325; tail jump as a thiscall stub')
S(0x602120, 'guard602120 (GUESS)', 'cdecl', None, ret='eax', gen=_gen_for('b'), note='batch325; else is a plain cdecl call')
