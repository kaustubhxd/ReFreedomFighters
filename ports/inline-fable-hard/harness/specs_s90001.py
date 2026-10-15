"""specs_s90001.py - hard trial (fable) batch 90001: 0x5af350 ZFFInventoryBridge::GetNoOf(EFFItemType), a 5-entry jump table with two
tail jumps. Both tail targets are hooked (this + the item type recorded, random count returned); the type covers every table entry,
both out-of-range neighbours, 0, -1 and random values."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _g5af350(c):
    clear_hooks(c)
    r = c.rng
    rets = [r.getrandbits(32) for _ in range(4)]
    hook_rec(c, 0x5af3a0, 1, this=True, ret=lambda em, k: rets[min(k, 3)])
    hook_rec(c, 0x5af430, 1, this=True, ret=lambda em, k: rets[min(k + 2, 3)])
    E = rnd(c, 0x20)
    t = r.choice([0xc, 0xd, 0xe, 0xf, 0x10, 0xb, 0x11, 0, 0xffffffff, r.getrandbits(32), r.randint(0, 0x20)])
    return [E, t]


S(0x5af350, 'GUESS ZFFInventoryBridge::GetNoOf', 'thiscall', None, ret='eax', gen=_g5af350, note='batch90001')
