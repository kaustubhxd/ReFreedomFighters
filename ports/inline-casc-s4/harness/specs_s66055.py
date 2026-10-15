"""specs_s66055.py - cascade s4 batch 66055: 0x603670 (register three handlers on a bounded global stack, then forward)."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _g603670(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    box = {'a': 0, 'clr': r.random() < 0.5, 'which': r.choice([0, 1, 2, 9])}

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))

    def h9940(em, rr):                    # 0x5f9940 (a, n1, n2) ret 0xc, ecx = this arg a
        k = box.setdefault('k', 0)
        box['k'] += 1
        em.calllog.append(('h9940', em.reg('ecx'), em.arg32(0), em.arg32(1), em.arg32(2)))
        if box['clr'] and k == box['which']:
            em.wbytes(box['a'] + 0xc, b'\0')
        em.ret(eax=0, argbytes=12)
    e.hook(0x5f9940, h9940)
    hook_rec(c, 0x5f9b80, 1, this=True)
    cnt = r.choice([0, 1, 0x2f, 0x30, 0x31, 0x32, 0x33, 0xffffffff, 5])
    e.w32(0x724698, cnt)
    e._image_dirty = True
    a = rnd(c, 0x20)
    box['a'] = a
    e.wbytes(a + 0xc, bytes([r.choice([0, 1, 1, 1, 7])]))
    t = rnd(c, 0x20)
    return [t, a]


S(0x603670, 'GUESS register handlers on a bounded global stack then forward (second)', 'thiscall', None, ret=None, gen=_g603670, note='batch66055')
