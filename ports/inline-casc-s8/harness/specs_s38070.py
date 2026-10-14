"""specs_s38070.py - cascade s8 batch 38070: 0x4a8230. thiscall(this) void. this+0x44 -> holder (+0x18 list L1), this+0x54 key (0 about half the time), this+0x4e unaligned index, this+0x48 owner id (7: owner with list L2,
8: owner without list, 9: null), this+0x4c word. Lists: begin (0x4c) / next (0x5c, stateful stub: it[0] = valid, it[1] = index; no stack address is logged) / id-at-index (0x30, ids 1..3) / count (0x14).
Engine system object: slots 0xe8 / 0xe4 return random bools; table slot 0x58 maps ids 0..4 to objects (0 -> null; objects have slot 0x1e0 with a random al and slot 0x124) and 7/8/9 to the owners.
0x4a85a0 is hooked (logs its argument)."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec


def _g4a8230(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def lslot(name, nargs, retf=lambda: 0):
        def h(em, res_):
            em.calllog.append((name, em.reg('ecx') != 0) + tuple(em.arg32(i) for i in range(nargs)))
            em.ret(eax=retf(), argbytes=4 * nargs)
        return e.stub_fn(name, h)

    def mklist(name, ids, idsel):
        def begin(em, res_):
            p = em.arg32(0)
            em.w32(p, 0)
            em.w32(p + 4, 0)
            em.w32(p + 8, 0)
            em.calllog.append((name + '-begin',))
            em.ret(eax=0, argbytes=4)

        def nxt(em, res_):
            p = em.arg32(0)
            i = em.r32(p + 4)
            ok = i < len(ids)
            em.w32(p, 1 if ok else 0)
            em.w32(p + 4, i + 1)
            em.calllog.append((name + '-next', i, ok))
            em.ret(eax=(ids[i] if ok else 0), argbytes=4)
        return obj(c, 0x40, {0x4c: e.stub_fn('begin', begin), 0x5c: e.stub_fn('next', nxt),
                             0x30: lslot(name + '-30', 1, lambda: r.choice(idsel)),
                             0x14: lslot(name + '-14', 0, lambda: r.choice([0, 1, 2, 3]))})
    L1 = mklist('L1', [r.choice([0, 1, 2, 3, 4]) for _ in range(r.choice([0, 1, 2, 3, 5]))], [1, 2, 3])
    L2 = mklist('L2', [r.choice([1, 2, 3, 4]) for _ in range(r.choice([0, 1, 2, 3]))], [1, 2, 3])

    def mkobj():
        return obj(c, 0x30, {0x1e0: lslot('o1e0', 1, lambda: (r.getrandbits(32) & ~0xff) | r.choice([0, 1])),
                             0x124: lslot('o124', 4)})
    objs = {i: mkobj() for i in range(1, 5)}
    owner7 = rnd(c, 0x30)
    e.w32(owner7 + 0x18, L2)
    owner8 = rnd(c, 0x30)
    e.w32(owner8 + 0x18, 0)
    objs[7] = owner7
    objs[8] = owner8

    def tget(em, res_):
        i = em.arg32(0)
        em.calllog.append(('tbl58', i))
        em.ret(eax=objs.get(i, 0), argbytes=4)
    sysobj(c, slots={0xe8: lslot('sys-e8', 1, lambda: r.getrandbits(32)), 0xe4: lslot('sys-e4', 1, lambda: r.getrandbits(32))},
           table_slots={0x58: e.stub_fn('tbl58', tget)})
    H = rnd(c, 0x30)
    e.w32(H + 0x18, L1)
    this = rnd(c, 0x70)
    e.w32(this + 0x44, H)
    e.w32(this + 0x54, r.choice([0, 0, 1, 2, 3]))
    e.wbytes(this + 0x4e, struct.pack('<I', r.randrange(4)))
    e.w32(this + 0x48, r.choice([7, 7, 8, 9]))
    hook_rec(c, 0x4a85a0, 1, this=True, pop=4)
    return [this]


S(0x4a8230, 'GUESS list cursor selection', 'thiscall', None, ret=None, gen=_g4a8230, note='batch38070')
