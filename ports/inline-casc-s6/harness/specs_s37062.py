"""specs_s37062.py - cascade s6 batch 37062 (0x56fc90). Format object at [[eng+0x9b]+0xae4] (slot 0: 2 args, returns a spec string); 0x56ef50 (1 arg: the line text is logged by
content) and 0x56fb10 hooked; this has the edit buffer at +0x1c9, a count array at +0x3b2, and objects at +0x5ca / +0x5ce / +0x5da / +0x5e2."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _cs(em, p):
    out = b''
    while len(out) < 300:
        b = em.rbytes(p, 1)
        if b == b'\0':
            break
        out += b
        p += 1
    return out


def _g56fc90(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))

    def h56ef50(em, res_):
        em.calllog.append(('line', _cs(em, em.arg32(0))))
        em.ret(eax=0, argbytes=4)
    e.hook(0x56ef50, h56ef50)
    hook_rec(c, 0x56fb10, 0, this=True)
    words = [b'', b'hi', b'hello world', b' x', b'abcdefghijklmnopqrstuvwxyz0123456789']
    text = b''
    for _ in range(r.choice([0, 1, 2, 3])):
        text += r.choice(words) + b'\n'
    text += r.choice(words)
    sp = e.alloc(len(text) + 8, 1)
    e.wbytes(sp, text + b'\0')
    fmt = obj(c, 0x20, {0x0: pystub(c, 2, this=True, ret=sp)})
    so = sysobj(c, table_size=0xb00)
    tab = e.r32(so + 0x9b)
    _w(c, tab + 0xae4, fmt)
    me = rnd(c, 0x600)
    for off, slot in ((0x5ca, 0x248), (0x5ce, 0x284), (0x5da, 0xbc), (0x5e2, 0x360)):
        _w(c, me + off, obj(c, 0x20, {slot: pystub(c, 1, this=True)}))
    _w(c, me + 0x198, r.choice([1, 1, 1, 0]), 1)
    cur = r.choice([b'', b'', b'abc', b'0123456789abcdef', b'0123456789abcdefghijklmnopqrs', b'0123456789abcdefghijklmnopqrst', b'0123456789abcdefghijklmnopqrstu', b'0123456789abcdefghijk'])
    _w(c, me + 0x1c9, int.from_bytes(cur + b'\0' + b'Z' * (0x3f - len(cur)), 'little'), 0x40)
    _w(c, me + 0x4b2, r.choice([0, 1, 5]))
    return [me]


S(0x56fc90, 'GUESS handle pasted text lines', 'thiscall', None, ret=None, gen=_g56fc90, note='batch37062')
