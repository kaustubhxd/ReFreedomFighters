"""specs_s1314.py - inventory thread batch 1314 (src/batch1314.cpp): ZItemSpawn::SpawnItem.

Owner item (IsA 0x1007d1), its template (slot 0x2e8), the new item from the template (slot 0x2c4), its class checks
(0x1007d2 or 0x1007d8), the reference table (ids), the game-side registration (0x46abf0, hooked), all logged.
"""
from pilot import S
from inv_helpers import Rec, rnd, set_global

SYS = 0x70039C
GAME = 0x7003B8


def _arg(emu, k):
    return emu.r32(emu.reg('esp') + 4 + 4 * k)


def spawn(c):
    r = Rec(c)
    sysobj = rnd(c, 0x2000, 4)
    set_global(c, SYS, sysobj)
    ref = rnd(c, 0x1000, 4)
    c.emu.w32(sysobj + 0x9B, ref)
    c.emu.w32(ref + 0xADC, c.rng.getrandbits(32))

    ids = {}
    objs = {}
    nxt = [0x40]

    def id_of(o):
        if o not in ids:
            nxt[0] += 4
            ids[o] = nxt[0]
            objs[nxt[0]] = o
        return ids[o]

    c.emu.w32(ref, r.vtable({
        0x4C: lambda emu, res: emu.ret(eax=id_of(_arg(emu, 0)), argbytes=4),
        0x58: lambda emu, res: emu.ret(eax=objs.get(_arg(emu, 0), 0), argbytes=4),
    }))

    # the new item (result of the template call): IsA answers from a sequence (1007d2 / 1007d8 / neither)
    seq = c.rng.choice([[1, 0], [0, 1], [0, 0], [1]])
    seq_state = {'i': 0}

    def isa_new(emu, res):
        i = seq_state['i']
        seq_state['i'] += 1
        v = seq[i] if i < len(seq) else 0
        emu.ret(eax=v, argbytes=4)

    newv = rnd(c, 0x40, 4)
    c.emu.w32(newv, r.vtable({
        0x1E0: isa_new,
        0x360: r.stub(20, 1, rand=True),
        0x364: r.stub(21, 0, rand=True),
        0x324: r.stub(22, 1, rand=True),
        0x2F0: r.stub(23, 3, rand=True),
        0x300: r.stub(24, 1, rand=True),
        0x7C: r.stub(25, 2, rand=True, quiet_args=(0, 1)),
    }))
    if c.rng.random() < 0.15:
        new_obj = 0
    else:
        new_obj = newv

    tmpl = rnd(c, 0x80, 4)
    c.emu.w32(tmpl, r.vtable({0x2C4: r.stub(26, 2, rets=[new_obj])}))

    owner = rnd(c, 0x80, 4)
    c.emu.w32(owner, r.vtable({
        0x1E0: r.stub(27, 1, rets=[c.rng.choice([1, 1, 0])]),
        0x2E8: r.stub(28, 0, rets=[tmpl if c.rng.random() < 0.9 else 0]),
        0x320: r.stub(29, 0, rand=True),
        0x80: r.stub(30, 2, rand=True, quiet_args=(0, 1)),
    }))
    objs[0x40] = owner

    self_obj = rnd(c, 0x200, 4)
    c.emu.w32(self_obj + 0x44, owner)
    c.emu.w32(self_obj + 0x52, c.rng.choice([0, 0, 0, 5]))
    c.emu.w32(self_obj + 0x5A, 0)
    c.emu.w32(self_obj, r.vtable({0x68: r.stub(31, 2, rand=True)}))

    game = rnd(c, 0x40, 4)
    set_global(c, GAME, game)
    r.hook(0x46ABF0, 32, 1, rand=True)
    return [self_obj]


S(0x471680, 'ZItemSpawn::SpawnItem', 'thiscall', None, ret=None, gen=spawn, note='batch1314')
