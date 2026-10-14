"""specs_s34117.py - 0x4ceae0: container with slots 0x4c (begin) and 0x64 (next item, 0..3 items then 0); engine object [0x700390] slot 0x20 returns a printer whose slot 0x2c is a cdecl recorder; [this+0x18] = 1..4 (items are 0x20-byte blocks of random dwords). The exe always has this non-null in the spec (null returns at once and is also generated in a tenth of the cases)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g4ceae0(c):
    clear_hooks(c)
    r = c.rng
    if r.random() < 0.1:
        return [0]
    items = [rnd(c, 0x20) for _ in range(r.choice([0, 1, 2, 3]))]

    def nxt_ret(em, k):
        return items[k] if k < len(items) else 0
    pr = obj(c, 0x20, {0x2c: pystub(c, 4, pop=0)}, nslots=0x30 // 4)
    eng = obj(c, 0x20, {0x20: pystub(c, 2, ret=pr, this=True)}, nslots=0x24 // 4)
    c.emu.w32(0x700390, eng)
    me = obj(c, 0x40, {0x4c: pystub(c, 1, this=True, stackmark=(0,)), 0x64: pystub(c, 1, this=True, stackmark=(0,), ret=nxt_ret)}, nslots=0x68 // 4)
    c.emu.w32(me + 0x18, r.choice([1, 2, 3, 4]))
    return [me]


S(0x4ceae0, 'GUESS log every item', 'thiscall', None, ret=None, gen=_g4ceae0, note='batch34117')
