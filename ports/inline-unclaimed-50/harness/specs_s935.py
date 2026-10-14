"""specs_s935.py - batch 935: 0x507c60 (ZActorIf::ReplaceMove, thiscall, one params arg, ret 4, void). Stand-ins: the accessor 0x5003d0 (thiscall;
returns the entry for its index), the engine logger (0x700390; slot +0x20 returns a sink), the sink (slot +0x2c cdecl printf: three words;
slot +0x30 cdecl: four words), the hook 0x7003b0 (installed; logs its ECX), the CRT _stricmp import (install_crt_str), the manager (g+0x9b; +0x44),
and the object X at this+0x18 (slots +0x598, +0x5c4, +0x5c8 return drawn dwords; +0x5b4 logs four words). The entries have a type byte at +4:
type 3 has a string pointer, type 4 an object with slot +0x34. The third entry's dword is the count (<= 0 takes the trace path). Names drawn among
Walk, Run, User0, User1 and other. The hooks are installed first; the globals are written after, so only_hooks cannot reset them."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object, install_crt_str


def _gen(c):
    e, r = c.emu, c.rng
    entries = []
    pick = r.choice([b'Walk', b'Run', b'User0', b'User1', b'other'])
    for k in range(3):
        # the first entry's value is read as a string (stricmp), so it must be type 3 or 4; the second may be anything
        t = r.choice([3, 4]) if k == 0 else r.choice([3, 3, 4, 0])
        E = rnd(c, 0x20)
        e.w8(E + 4, t)
        if t == 3:
            e.w32(E, e.cstr(pick.decode()) if k != 2 else 0)
        elif t == 4:
            e.w32(E, 0)     # set below to the object
        else:
            e.w32(E, r.getrandbits(32))
        entries.append(E)
    e.w32(entries[2], r.choice([0, 1, 3, 0xffffffff]))   # the count

    rv34 = e.cstr(pick.decode())      # a valid string for the type-4 path (esi is read as a string)

    def obj34(e, rr):
        e.calllog.append(('o.34',))
        e.ret(eax=rv34, argbytes=0)

    o34 = vt_object(c, 0x40, {0x34: obj34}, nslots=0x40, name='o34')
    for E in entries:
        if e.r8(E + 4) == 4:
            e.w32(E, o34)

    def acc(e, rr):
        idx = e.arg32(0)
        e.calllog.append(('acc.5003d0', idx))
        e.ret(eax=entries[idx], argbytes=4)

    install_crt_str(c)
    only_hooks(c, {0x5003d0: acc})

    def sink_pf(e, rr):
        e.calllog.append(('sink.2c', e.arg32(1) != 0, e.arg32(2) != 0))
        e.ret(eax=0, argbytes=0)

    def sink_tr(e, rr):
        e.calllog.append(('sink.30', e.arg32(1) != 0, e.arg32(2), e.arg32(3)))
        e.ret(eax=0, argbytes=0)

    sink = vt_object(c, 0x40, {0x2c: sink_pf, 0x30: sink_tr}, nslots=0x40, name='sink')

    def logw(e, rr):
        e.calllog.append(('log.20', e.arg32(0) != 0, e.arg32(1)))
        e.ret(eax=sink, argbytes=8)

    logger = vt_object(c, 0x40, {0x20: logw}, nslots=0x40, name='logger')

    def hook(e, rr):
        e.calllog.append(('hook.7003b0', e.reg('ecx') == e.r32(sink)))
        e.ret(eax=0, argbytes=0)

    hookaddr = e.stub_fn('hook7003b0', hook)
    g = rnd(c, 0x1b00)
    mgr = rnd(c, 0x100)
    e.w32(mgr + 0x44, r.getrandbits(32))
    e.w32(g + 0x9b, mgr)
    e.w32(0x70039c, g)
    e.w32(0x700390, logger)
    e.w32(0x7003b0, hookaddr)

    def rv(name, nargs):
        def h(e, rr):
            e.calllog.append((name,) + tuple(e.arg32(k) for k in range(nargs)))
            e.ret(eax=r.getrandbits(32), argbytes=4 * nargs)
        return h

    X = vt_object(c, 0x40, {0x598: rv('x.598', 1), 0x5c4: rv('x.5c4', 1), 0x5c8: rv('x.5c8', 1), 0x5b4: rv('x.5b4', 4)},
                  nslots=0x800, name='X')
    self = rnd(c, 0x40)
    e.w32(self + 0x18, X)
    p = rnd(c, 0x10)
    e.w32(p + 4, rnd(c, 0x10))
    return [self, p]


S(0x507c60, 'ZActorIf::ReplaceMove (named)', 'thiscall', None, ret=None, gen=_gen, note='area50 batch935 (core slice)')
