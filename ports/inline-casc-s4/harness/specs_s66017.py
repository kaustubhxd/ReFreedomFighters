"""specs_s66017.py - cascade s4 batch 66017: 0x51fd70 (register three handlers on a bounded global stack, then forward)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g51fd70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    box = {'a': 0, 'clr': r.random() < 0.5}

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        if box['clr']:
            e2.wbytes(box['a'] + 0xc, b'\0')
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    hook_rec(c, 0x51b270, 1, this=True)
    cnt = r.choice([0, 1, 0x2f, 0x30, 0x31, 0x32, 0x33, 0xffffffff, 5])
    e.w32(0x7019a8, cnt)
    e._image_dirty = True
    t = obj(c, 0x60, {0x44: pystub(c, 1, this=True)})
    a = rnd(c, 0x20)
    box['a'] = a
    e.wbytes(a + 0xc, bytes([r.choice([0, 1, 1, 1, 7])]))
    return [t, a]


S(0x51fd70, 'GUESS register handlers on a bounded global stack then forward', 'thiscall', None, ret=None, gen=_g51fd70, note='batch66017')
