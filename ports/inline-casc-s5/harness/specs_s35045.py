"""specs_s35045.py - 0x5f53f0 (thiscall(p) ret 4, ret='eax' = the slot pointer). Pool object: [0] entries (16 entries of 8 bytes), [4] capacity 1..16, [8] next index (at capacity in 1/5 so the
0x42ab62 + assert path runs; entries stay inside the 16-entry block either way) with kind bytes 0, 2 or other; 0x42ab62 hooked (cdecl, 1 arg); assert hook always set (random EAX); logger at 0x700390
(slot 0x20 -> object with slot 0x2c, 3 args, caller-popped)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g5f53f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x42ab62, 1, pop=0)

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    lg2 = obj(c, 0x20, {0x2c: pystub(c, 3, this=True, pop=0)}, nslots=0x20)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True)}, nslots=0x20)
    e.w32(0x700390, lg)
    ents = rnd(c, 0x80)
    for i in range(16):
        e.wbytes(ents + 8 * i + 4, bytes([r.choice([0, 3, 3, 0, 1, 2, r.getrandbits(8)])]))
    cap = r.randint(1, 16)
    idx = cap if r.random() < 0.2 else r.randrange(cap)
    me = rnd(c, 0x10)
    e.w32(me, ents)
    e.w32(me + 4, cap)
    e.w32(me + 8, idx if idx < 16 else 15)
    if idx >= cap:
        e.w32(me + 8, min(cap, 15))
    return [me, r.getrandbits(32)]


S(0x5f53f0, 'GUESS hand out next pool slot', 'thiscall', None, ret='eax', gen=_g5f53f0, note='batch35045')
