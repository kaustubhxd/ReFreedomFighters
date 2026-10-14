"""specs_s35002.py - 0x555c60. Struct with [s+4], [s+8]; hooked 0x5003d0 (thiscall 1 arg, returns a record whose byte +4 is 0, 1 or another value (log+assert path through the
object at 0x700390 and the hook at 0x7003b0)), 0x5002f0 (thiscall 1 arg); engine table slot 0x58 returns an entry (null in a third) whose [+8] block has a random dword at +0x3c."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, sysobj


def _g555c60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rec = rnd(c, 0x20)
    e.wbytes(rec + 4, bytes([r.choice([0, 1, 2, 0x80, r.getrandbits(8)])]))
    hook_rec(c, 0x5003d0, 1, this=True, ret=rec)
    hook_rec(c, 0x5002f0, 1, this=True)
    lg2 = obj(c, 0x20, {0x2c: pystub(c, 3, this=True, pop=0)}, nslots=0x20)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True)}, nslots=0x20)
    e.w32(0x700390, lg)

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    if r.random() < 1 / 3:
        ent = 0
    else:
        blk = rnd(c, 0x60)
        ent = rnd(c, 0x20)
        e.w32(ent + 8, blk)
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=ent, this=True)})
    return [rnd(c, 0x20)]


S(0x555c60, 'GUESS resolve record, apply flag 0x1000', 'stdcall', None, ret=None, gen=_g555c60, note='batch35002')
