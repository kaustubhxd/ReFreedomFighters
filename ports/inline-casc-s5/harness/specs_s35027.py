"""specs_s35027.py - 0x41f720 (thiscall(pp, b, c) ret 0xc). Region R: pool at R+0x100 (unaligned dword [[engine+0x9b]+0x1c5d]; null in 1/6, pool[-8] = size 0..0x40 plus random top bits); the string data pointer d is
before the pool, inside it, or after its end, with a refcount (1 in 1/3, else 2..5; also 0 and negative values) and a length word at d-0xc / d-8. Assert hook 0x7003b0 always set. Vtable slots 0xb0 (3 args) and
0xa8 (1 arg, returns a heap block); 0x634d22 cdecl recorder, 0x41f190 thiscall recorder."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, sysobj


def _g41f720(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    hook_rec(c, 0x634d22, 3, pop=0)
    hook_rec(c, 0x41f190, 1, this=True)
    R = rnd(c, 0x400)
    pool = R + 0x100
    size = r.randint(0, 0x40)
    where = r.choice(['before', 'inside', 'inside', 'after'])
    if where == 'inside' and size > 0:
        d = pool + r.randrange(size)
    elif where == 'after':
        d = pool + size + r.randint(0, 0x20)
    else:
        d = R + 0x20 + 4 * r.randrange(4)
    rc = r.choice([1, 1, 2, 3, 5, 0, 0xffffffff])
    e.w32(d - 0xc, rc)
    e.w32(d - 8, r.choice([0, 4, 0x10, 0x30, r.getrandbits(32)]))
    e.w32(pool - 8, size | (r.getrandbits(3) << 29))
    so = sysobj(c, table_size=0x2000)
    tab = e.r32(so + 0x9b)
    p = 0 if r.random() < 1 / 6 else pool
    e.wbytes(tab + 0x1c5d, p.to_bytes(4, 'little'))
    nb = rnd(c, 0x40)
    me = obj(c, 0x20, {0xb0: pystub(c, 3, this=True, ret=r.getrandbits(32)), 0xa8: pystub(c, 1, this=True, ret=nb)}, nslots=0x2c)
    pp = rnd(c, 4)
    e.w32(pp, d)
    return [me, pp, r.getrandbits(32), r.getrandbits(32)]


S(0x41f720, 'GUESS make counted string unique', 'thiscall', None, ret=None, gen=_g41f720, note='batch35027')
