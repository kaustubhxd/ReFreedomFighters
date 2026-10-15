"""specs_s67532.py - cascade s6 batch 67532 (0x461790, thiscall(rec) ret 4, returns al). rec (null sometimes) has a type block at +0xc (dword +0x23, bit 0x100000 in the first test) and a chain at
+0x54; chain records hold sub-records (+0x54: type block, name pointer at +4) and a name holder (+0x50); 0x4db520 (next) is a hook, the string compare at 0x676414 is a cdecl recorder, 0x4dc110
and 0x4690b0 run unhooked. The logger at 0x700390 has slot 0x20 (2 args) returning an object whose cdecl slot 0x2c is a custom logger (3 args when fmt is 0x6858e8, else 5)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g461790(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def cmp(em, res_):
        a0, a1 = em.arg32(0), em.arg32(1)
        em.calllog.append(('cmp', a0, a1))
        em.ret(eax=r.choice([0, 0, 1, 7]), argbytes=0)
    e.w32(0x676414, e.stub_fn('recorder', cmp))

    def lg2c(em, res_):
        f = em.arg32(1)
        n = 3 if f == 0x6858e8 else 5
        em.calllog.append(('log', tuple(em.arg32(i) for i in range(1, n))))
        em.ret(eax=0, argbytes=0)
    x = obj(c, 0x20, {0x2c: e.stub_fn('recorder', lg2c)})
    lgo = obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=x)})
    e.w32(0x700390, lgo)

    def mk_blk(bit):
        b = rnd(c, 0x40)
        _w(c, b + 0x23, (r.getrandbits(32) | 0x100000) if bit else (r.getrandbits(32) & ~0x100000))
        return b

    def mk_sub(bit):
        s = rnd(c, 0x70)
        _w(c, s + 0xc, mk_blk(bit))
        _w(c, s + 4, r.choice([0, rnd(c, 0x10)]))
        return s
    chain = []
    for _ in range(r.choice([0, 1, 2, 3, 4])):
        ch = rnd(c, 0x70)
        mode = r.random()
        if mode < 0.15:
            _w(c, ch + 0x54, 0)
        else:
            _w(c, ch + 0x54, mk_sub(r.random() < 0.2))
        h = rnd(c, 0x70)
        _w(c, h + 0x54, r.choice([0, mk_sub(False)]))
        _w(c, ch + 0x50, h)
        chain.append(ch)
    hook_rec(c, 0x4db520, 0, this=True, ret=lambda em, k: r.choice(chain + [0]))
    rec = rnd(c, 0x70) if r.random() < 0.9 else 0
    if rec:
        _w(c, rec + 0xc, mk_blk(r.random() < 0.75))
        _w(c, rec + 0x54, r.choice(chain + [0]) if chain else 0)
        _w(c, rec + 4, r.choice([0, rnd(c, 0x10)]))
    ret20 = rnd(c, 0x10)
    _w(c, ret20 + 4, r.choice([0, rnd(c, 0x10)]))
    t = obj(c, 0x70, {0x2d0: pystub(c, 1, this=True), 0x20: pystub(c, 0, this=True, ret=ret20)})
    _w(c, t + 4, r.choice([0, rnd(c, 0x10)]))
    return [t, rec]


S(0x461790, 'GUESS find_named_record', 'thiscall', None, ret='al', gen=_g461790, note='batch67532')
