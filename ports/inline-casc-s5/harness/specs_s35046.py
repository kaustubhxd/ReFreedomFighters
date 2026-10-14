"""specs_s35046.py - 0x5b2bd0 (thiscall(id, p) ret 8, ret='eax'). Seven id words at +0x240.. (distinct small values, with some equal pairs); id chosen to hit each of them, to hit none, or random with garbage
upper bits; p null in a quarter, else pointing at a dword that is zero in half the cases; 0x5b5420 (thiscall) and 0x5b5370 (thiscall, 1 arg) hooked. The object is random bytes so the target bytes are observable."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _g5b2bd0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x5b5420, 0, this=True)
    hook_rec(c, 0x5b5370, 1, this=True)
    me = rnd(c, 0x260)
    offs = [0x240, 0x242, 0x244, 0x246, 0x24a, 0x24c, 0x24e]
    ws = [r.randint(1, 40) for _ in offs]
    if r.random() < 0.25:
        ws[r.randrange(7)] = ws[r.randrange(7)]
    for o, w in zip(offs, ws):
        e.wbytes(me + o, w.to_bytes(2, 'little'))
    if r.random() < 0.8:
        w = r.choice(ws)
    else:
        w = r.randint(41, 60)
    idv = w | (r.getrandbits(16) << 16 if r.random() < 0.5 else 0)
    if r.random() < 0.25:
        p = 0
    else:
        p = rnd(c, 4)
        if r.random() < 0.5:
            e.w32(p, 0)
    return [me, idv, p]


S(0x5b2bd0, 'GUESS dispatch input id to action', 'thiscall', None, ret='eax', gen=_g5b2bd0, note='batch35046')
