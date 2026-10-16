"""specs_s213059.py - batch 213059: string constant selector by record byte, flag and object type, Sonnet-w3b."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g474070(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ret_1e0 = lambda emu, k: r.choice([0, 0, 0x100, 0x5500, 1, 0xff, r.getrandbits(32)])
    ret_21c = lambda emu, k: r.choice([0, 0, 1, 0x689ce0, r.getrandbits(32)])
    this = obj(c, 0x20, {0x1e0: pystub(c, 1, ret=ret_1e0, this=True),
                         0x21c: pystub(c, 1, ret=ret_21c, this=True)}, nslots=0x90)
    if r.random() < 0.15:
        o = 0
    else:
        t = r.choice([9, 9, 8, 8, 8, 0, 1, 7, r.getrandbits(32), r.randint(0, 12)])
        o = obj(c, 0x20, {0x330: pystub(c, 0, ret=t, this=True)}, nslots=0xd0)
        e.w32(o + 4, r.choice([0, rnd(c, 16)]))
    hook_rec(c, 0x4cc850, 0, ret=lambda emu, k: r.choice([0, 1, r.getrandbits(32)]), pop=0, this=True,
             side=lambda emu, k: emu.calllog.append(('edx', emu.reg('edx'))))
    a = rnd(c, 8)
    e.wbytes(a, bytes([r.choice([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 10, 0xff, r.getrandbits(8)]),
                       r.choice([0, 0, 1, r.getrandbits(8)])]))
    flag = r.choice([0, 1, 0xff, r.getrandbits(8), r.getrandbits(32)])
    return [this, a, flag, o]


S(0x474070, 'record_name_string', 'thiscall', None, ret='eax', gen=g474070)
