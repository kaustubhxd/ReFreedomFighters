"""specs_s90000.py - hard trial opus2 batch 90000: 0x5af350 (thiscall(type) switch over item types 12..16 through a jump table).
type: mostly 10..18 (both edges of the table range), sometimes a random dword or a value that wraps below 12 (unsigned check);
this: a random-filled block; both tail-jump targets are hooked with ECX and the argument recorded and a random return value."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _g5af350(c):
    clear_hooks(c)
    r = c.rng
    va = [r.getrandbits(32) for _ in range(8)]
    vb = [r.getrandbits(32) for _ in range(8)]
    hook_rec(c, 0x5af3a0, 1, ret=lambda em, k: va[min(k, 7)], this=True)
    hook_rec(c, 0x5af430, 1, ret=lambda em, k: vb[min(k, 7)], this=True)
    self = rnd(c, 0x20)
    k = r.random()
    if k < 0.75:
        t = r.randrange(10, 19)
    elif k < 0.85:
        t = (r.randrange(0, 12) - 12) & 0xffffffff
    else:
        t = r.getrandbits(32)
    return [self, t]


S(0x5af350, 'ZFFInventoryBridge::GetNoOf(EFFItemType)', 'thiscall', None, ret='eax', gen=_g5af350, note='batch90000')
