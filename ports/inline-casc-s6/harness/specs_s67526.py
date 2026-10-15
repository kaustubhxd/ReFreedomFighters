"""specs_s67526.py - cascade s6 batch 67526 (0x440940, thiscall(out, b, flag) ret 0xc). The eleven vector helpers are Python hooks (fastcall ones read ecx / edx, thiscall ones ecx + a
stack pointer): each logs the 12-byte contents of the vectors it receives (stack addresses never recorded) and the output ones write deterministic bytes into their destination, the
in/out ones rewrite the first dword. Children form a chain (+0x60) with flags (+0x3c) and optional sub-objects (+0x54 -> record whose +0xc points at a block with the type dword at +0x23
and a slot 0x2bc that fills two stack vectors)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g440940(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    st = {'k': 0}

    def vec(em, a):
        return em.rbytes(a, 12)

    def fill(em, a, tag):
        k = st['k']
        em.wbytes(a, bytes((tag * 31 + k * 7 + i * 3) & 0xff for i in range(12)))

    def mk_fast(addr, kind):
        def h(em, res_):
            k = st['k']
            st['k'] += 1
            ecx, edx = em.reg('ecx'), em.reg('edx')
            if kind == 'rec':      # 4e2c60: ecx = child, edx = vector (in/out)
                em.calllog.append(('4e2c60', vec(em, edx)))
                em.wbytes(edx, bytes((b ^ 0x55) for b in vec(em, edx)))
                em.ret(eax=0, argbytes=0)
            elif kind == 'e_v':    # 4419f0: ecx = vector (in/out), edx = child
                em.calllog.append((hex(addr), vec(em, ecx)))
                em.wbytes(ecx, bytes((b + 1) & 0xff for b in vec(em, ecx)))
                em.ret(eax=0, argbytes=0)
            elif kind == 'v_p':    # 441940: ecx = vector (in/out), edx = pointer to a vector inside the child
                em.calllog.append((hex(addr), vec(em, ecx), vec(em, edx)))
                em.wbytes(ecx, bytes((b + 2) & 0xff for b in vec(em, ecx)))
                em.ret(eax=0, argbytes=0)
            elif kind == 'out3':   # 43e8e0 / 43e920: ecx = dst, edx = a, stack = b
                bptr = em.arg32(0)
                em.calllog.append((hex(addr), vec(em, edx), vec(em, bptr)))
                fill(em, ecx, addr & 0xff)
                em.ret(eax=0, argbytes=4)
            elif kind == 'acc':    # 4e08d0 / 4e0900: ecx = accumulator (in/out), edx = vector
                em.calllog.append((hex(addr), vec(em, ecx), vec(em, edx)))
                em.wbytes(ecx, bytes((a ^ b) & 0xff for a, b in zip(vec(em, ecx), vec(em, edx))))
                em.ret(eax=0, argbytes=0)
            elif kind == 'scale':  # 4e0d00: ecx = vector (in/out), stack = scale bits
                em.calllog.append((hex(addr), vec(em, ecx), em.arg32(0)))
                em.wbytes(ecx, bytes((b + 3) & 0xff for b in vec(em, ecx)))
                em.ret(eax=0, argbytes=4)
        e.hook(addr, h)
    mk_fast(0x4e2c60, 'rec')
    mk_fast(0x4419f0, 'e_v')
    mk_fast(0x441940, 'v_p')
    mk_fast(0x43e8e0, 'out3')
    mk_fast(0x43e920, 'out3')
    mk_fast(0x4e08d0, 'acc')
    mk_fast(0x4e0900, 'acc')
    mk_fast(0x4e0d00, 'scale')

    def mk_this(addr, tag):
        def h(em, res_):
            st['k'] += 1
            fill(em, em.arg32(0), tag)
            em.calllog.append((hex(addr), em.reg('ecx') if 0x20000000 <= em.reg('ecx') < 0x30000000 else 1))
            em.ret(eax=0, argbytes=4)
        e.hook(addr, h)
    mk_this(0x4daf90, 1)
    mk_this(0x4db7c0, 2)
    hook_rec(c, 0x4daa00, 0, this=True, ret=lambda em, k: r.choice([0, 0, 0, 1, 0x100]))

    def s2bc(em, k):
        em.wbytes(em.arg32(0), bytes((k * 9 + 1 + i) & 0xff for i in range(12)))
        em.wbytes(em.arg32(1), bytes((k * 5 + 2 + i) & 0xff for i in range(12)))
        em.calllog.append(('2bc', em.arg32(2)))
    chain = []
    for _ in range(r.choice([0, 1, 2, 3, 4])):
        ch = rnd(c, 0x70)
        _w(c, ch + 0x3c, r.choice([0, 0, 0x400, 0x800, 0xc00, 0x1]))
        mode = r.random()
        if mode < 0.4:
            blk = rnd(c, 0x40)
            _w(c, blk + 0x23, r.choice([0x100000, 0, 0x300000, 0x1]))
            sub = obj(c, 0x20, {0x2bc: pystub(c, 3, this=True, stackmark=(0, 1), side=s2bc)})
            _w(c, sub + 0xc, blk)
            _w(c, ch + 0x54, sub)
        else:
            _w(c, ch + 0x54, 0)
        chain.append(ch)
    for i, ch in enumerate(chain):
        _w(c, ch + 0x60, chain[i + 1] if i + 1 < len(chain) else 0)
    t = rnd(c, 0x70)
    _w(c, t + 0x50, chain[0] if chain else 0)
    out = rnd(c, 0x10)
    b = rnd(c, 0x10)
    return [t, out, b, r.choice([0, 1, 0x100, 0x101, 0xffffffff])]


S(0x440940, 'GUESS bounds_of_children', 'thiscall', None, ret=None, gen=_g440940, note='batch67526')
