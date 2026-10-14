"""specs_s304.py - mounted gun batch 304: CMachinegunControlGroup::Command (message dispatch)."""
from pilot import S
from mg_helpers import _obj, _stub, flush
from nest_fixture import nest, put

MSGS = [0x714350 + 4 * i for i in range(13)]


def _cmd(c):
    r = c.rng
    n = nest(c)
    ids = r.sample(range(1, 0x10000), 13)
    if r.random() < 0.1:
        i, j = r.sample(range(13), 2)
        ids[j] = ids[i]
    for a, v in zip(MSGS, ids):
        c.emu.w16(a, v)
    pr = _obj(c, 8, {0x2c: _stub(c, 2, pop=0, this=True)})
    lg = _obj(c, 8, {0x20: _stub(c, 2, ret=pr, this=True)})
    c.emu.w32(0x700390, lg)
    k = r.randrange(14)
    msg = ids[k] if k < 13 else r.getrandbits(16)
    msg |= r.getrandbits(16) << 16      # only the low word is the argument
    s, refs = n['self'], n['ids']
    buf = put(c, [c.fv(-500, 500) for _ in range(3)])
    ref = r.choice([refs[4], refs[5], 0, refs[7], c.emu.r32(s + 0x88)])
    c.emu.w32(buf, r.choice([refs[4], refs[5], 0]) if r.random() < 0.5 else c.emu.r32(buf))
    idx = k if k < 13 else -1
    data = ref if idx in (2, 4, 7, 9) else buf
    flush(c)
    return [s, msg, data]


S(0x5c8a80, 'CMachinegunControlGroup::Command', 'thiscall', None, ret='eax', gen=_cmd, note='batch304')
