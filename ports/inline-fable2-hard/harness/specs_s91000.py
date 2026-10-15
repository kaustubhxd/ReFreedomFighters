"""specs_s91000.py - hard trial (fable 2) batch 91000: 0x5a3710 MP_GameController ctor.
Engine object [0x70039c] (sysobj, 0x2000 bytes: the ctor writes eng+0x1b5d); [eng+0x9b] table: slot 0x134 -> settings z, slot 0x114 (name, 0,
file, line) -> message id (random dword, only ax kept), slot 0x138 -> routing object with slot 0x60(name, handle, 4).
Settings z: slot 0x90 (name, &bool) writes one random byte (the ctor branches on it), slot 0x88 (name, &int) writes a random dword,
slots 0x68/0x5c/0x40/0x58 recorded with 3 args. [0x7003b8]: object that receives this at +0x2c21.
[0x70038c] memory manager M: slot 0x20(obj) random 0/nonzero, M+8 resolver (thiscall, 0 args) or 0, M+0xc..M+0x10 range around E or not,
slot 0xac(obj) recorder; the word before E random 0/nonzero. 0x41e290 (operator new) hooked: returns prepared 0x1c blocks or 0;
0x4ccbe0 (list ctor) hooked: records (this, 4, 0), returns this. 0x469870 (base ctor) hooked."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g5a3710(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rets = [r.getrandbits(32) for _ in range(64)]
    cnt = [0]

    def nxt(em=None, k=None):
        v = rets[cnt[0] % len(rets)]
        cnt[0] += 1
        return v
    mpflag = r.choice([0, 0, 1, 0xff, r.getrandbits(8)])
    kothv = r.choice([0, 1, 0x100, r.getrandbits(32)])

    def z90(em, res):   # (name, &bool): name is an image address, &bool a stack address (logged as a flag)
        em.calllog.append(('z90', em.reg('ecx'), em.arg32(0), 1 if em.arg32(1) else 0))
        em.wbytes(em.arg32(1), bytes([mpflag]))
        em.ret(eax=nxt(), argbytes=8)

    def z88(em, res):   # (name, &int)
        em.calllog.append(('z88', em.reg('ecx'), em.arg32(0), 1 if em.arg32(1) else 0))
        em.w32(em.arg32(1), kothv)
        em.ret(eax=nxt(), argbytes=8)
    z = obj(c, 0x20, {0x90: e.stub_fn('z90', z90), 0x88: e.stub_fn('z88', z88),
                      0x68: pystub(c, 3, this=True, ret=nxt), 0x5c: pystub(c, 3, this=True, ret=nxt),
                      0x40: pystub(c, 3, this=True, ret=nxt), 0x58: pystub(c, 3, this=True, ret=nxt)})
    rout = obj(c, 0x20, {0x60: pystub(c, 3, this=True, ret=nxt)})
    sysobj(c, slots={}, table_slots={0x134: pystub(c, 0, this=True, ret=z), 0x114: pystub(c, 4, this=True, ret=nxt),
                                     0x138: pystub(c, 0, this=True, ret=rout)}, table_size=0x140)
    e.w32(0x7003b8, rnd(c, 0x2c30))
    # the object: 4 bytes before it hold the handle word; fields up to 0x137
    blk = rnd(c, 0x150, 16)
    E = blk + 4
    e.w32(E - 4, r.choice([0, 0, r.getrandbits(32)]))
    # memory manager
    resolver = pystub(c, 0, this=True, ret=nxt)
    M = obj(c, 0x40, {0x20: pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 0, 1, nxt()])),
                      0xac: pystub(c, 1, this=True, ret=nxt)})
    e.w32(M + 8, r.choice([0, resolver, resolver]))
    lo, hi = r.choice([(E - 0x100, E + 0x100), (E, E + 1), (E + 1, E + 0x100), (E - 0x100, E), (0, 0xffffffff), (E - 8, E - 4)])
    e.w32(M + 0xc, lo)
    e.w32(M + 0x10, hi)
    e.w32(0x70038c, M)
    hook_rec(c, 0x469870, 0, this=True, ret=nxt)
    blocks = [r.choice([rnd(c, 0x1c), rnd(c, 0x1c), rnd(c, 0x1c), 0]) for _ in range(4)]
    hook_rec(c, 0x41e290, 1, pop=0, ret=lambda em, k: blocks[k % 4])
    hook_rec(c, 0x4ccbe0, 2, this=True, ret=lambda em, k: em.reg('ecx'))
    return [E]


S(0x5a3710, 'GUESS MP_GameController::MP_GameController', 'thiscall', None, ret='eax', gen=_g5a3710, note='batch91000')
