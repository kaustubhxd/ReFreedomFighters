"""specs_s1677.py - residue 13 batch 1677: 0x46a290 (ZItem-family constructor). The system object (0x70039c) has a vtable with
slot 0x1a4 (recorder) and manager +0x9b with slot 0x114 (random message ids). ZItem::ZItem (0x469980), REFTAB (0x4ccbe0),
0x4d83b0 are hooked by address; 0x41e290 (cdecl allocator) is hooked and returns two random pointers (or zero) in order."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, hook, HOOKED, sysobj


def _newhook(c, vals):
    cnt = c.emu.alloc(4, 4)

    def h(e, r):
        i = e.r32(cnt)
        e.w32(cnt, i + 1)
        e.ret(eax=vals[i % len(vals)], argbytes=0)
    HOOKED.add(0x41e290)
    c.emu.hook(0x41e290, h)


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    hook(c, seq, 0x469980, 3, ret=0, this=True, pop=True)
    hook(c, seq, 0x4ccbe0, 2, ret=r.getrandbits(32), this=True, pop=True)
    hook(c, seq, 0x4d83b0, 3, ret=r.getrandbits(32), this=True, pop=True)
    p1 = rnd(c, 0x40) if r.random() < 0.8 else 0
    p2 = rnd(c, 0x40) if r.random() < 0.8 else 0
    _newhook(c, [p1, p2])
    ids = [r.getrandbits(16) for _ in range(4)]
    R = obj(c, 0x100, {0x114: stub(c, seq, 4, ret=r.getrandbits(32),
                                   retfn=[(3, 0x8eb, ids[0]), (3, 0x8ec, ids[1]), (3, 0x8ed, ids[2]), (3, 0x8ee, ids[3])])})
    sysobj(c, db=R)
    sys_ = c.emu.r32(0x70039c)
    vt = obj(c, 0x40, {0x1a4: stub(c, seq, 1)})
    c.emu.w32(sys_, c.emu.r32(vt))
    me = rnd(c, 0x200)
    return [me, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x46a290, 'GUESS FUN_46a290', 'thiscall', None, ret='eax', gen=_gen, note='batch1677; ZItem-family ctor; SEH not reproduced')
