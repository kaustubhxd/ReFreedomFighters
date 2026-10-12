"""specs_s6510.py - unclaimed-68 batch 51 (claim 51): ZSoundAmbient::CanPlayInRoom (0x4a3d60, GUESS name), thiscall with one stack argument (ret 4).
Two embedded lists: A at this+0x5c and B at this+0x108 (logging vtables: slot 0x14 non-empty flag, 0x4c reset, 0x5c next element with an
out pointer that is nonzero while elements remain). The engine's manager (engine+0x9b) has slot 0x58 (v & 0xf) and a threshold at +0xadc."""
from pilot import S
from engine_stubs import zero_obj, set_global


def _slot(name, off, n, f):
    # logs like logging_vtable, but a pointer argument of the out-slots is logged as '&out': the port's out pointer is its own
    # stack local, whose address differs from the original's by a few bytes (not part of this function's behaviour)
    def h(e, r):
        args = [e.arg32(k) for k in range(n)]
        e.calllog.append((name, off, e.reg('ecx'), tuple('&out' if off in (0x4c, 0x5c) else a for a in args)))
        eax, st0 = f(e, args)
        e.ret(eax=eax, argbytes=4 * n, st0=st0)
    return h


def _list(c, items):
    st = {'pos': 0}
    name = 'ZSoundAmbientList'

    def nonempty(e, a):
        return (1 if items else 0, None)

    def reset(e, a):
        st['pos'] = 0
        e.w32(a[0], 1 if items else 0)
        return (None, None)

    def nxt(e, a):
        if st['pos'] < len(items):
            v = items[st['pos']]
            st['pos'] += 1
            e.w32(a[0], st['pos'])
            return (v, None)
        e.w32(a[0], 0)
        return (0, None)

    slots = {0x14: _slot(name, 0x14, 0, nonempty), 0x4c: _slot(name, 0x4c, 1, reset), 0x5c: _slot(name, 0x5c, 1, nxt)}
    return c.emu.fake_vtable(name, 0x80, slots)


def _gen(c):
    o = zero_obj(c, 0x200)
    eng = zero_obj(c, 0x400)
    mgr = zero_obj(c, 0x1000)
    c.emu.w32(mgr + 0xadc, c.rng.randrange(0, 16))
    c.emu.w32(eng + 0x9b, mgr)
    set_global(c, 0x70039c, eng)
    mvt = c.emu.logging_vtable('ZSoundMgrRoom', 0x80, impl={0x58: lambda e, a: (a[0] & 0xf, None)}, argwords={0x58: 1})
    c.emu.w32(mgr, mvt)
    a_items = [c.rng.randrange(0, 16) for _ in range(c.rng.randrange(0, 4))]
    b_items = [c.rng.randrange(0, 16) for _ in range(c.rng.randrange(0, 4))]
    c.emu.w32(o + 0x5c, _list(c, a_items))
    c.emu.w32(o + 0x108, _list(c, b_items))
    return [o, c.rng.randrange(0, 16)]


S(0x4a3d60, 'ZSoundAmbient::CanPlayInRoom (GUESS) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-68 batch 51; list A at +0x5c and list B at +0x108; mgr slot +0x58 maps the element; mgr +0xadc is the excluded room')
