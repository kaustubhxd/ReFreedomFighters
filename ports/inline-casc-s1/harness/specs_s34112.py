"""specs_s34112.py - 0x63ade0 / 0x6483e0: node list (link +8, word +2 either 0xffff or live), head at [this+8]; hooked helper (plain, low byte random) and tail targets record ecx (clobbered by the helper).
0x528090: counts 0..3 at the unaligned +0x8d / +0x91; 0x62f340: two linked buffer descriptors; 0x4cd690: string duplicate."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec
from unicorn.x86_const import UC_X86_REG_ECX


def _walker(helper, tail):
    def g(c):
        clear_hooks(c)
        r = c.rng
        hook_rec(c, helper, 0, this=True, pop=0, ret=lambda em, k: r.choice([0, 1, 0x100, 0x101, r.getrandbits(32)]),
                 side=lambda em, k: em.mu.reg_write(UC_X86_REG_ECX, r.getrandbits(32)))
        hook_rec(c, tail, 0, this=True, pop=0, ret=r.getrandbits(32))
        me = rnd(c, 0x20)
        k = r.choice([0, 1, 2, 3, 4])
        nodes = [rnd(c, 0x20) for _ in range(k)]
        for i, n in enumerate(nodes):
            c.emu.wbytes(n + 2, (0xffff if r.random() < 0.6 else r.choice([0, 1, 0x7fff])).to_bytes(2, 'little'))
            nxt = nodes[i + 1] if i + 1 < k else (nodes[0] if r.random() < 0.4 else 0)
            c.emu.w32(n + 8, nxt)
        c.emu.w32(me + 8, nodes[0] if k else 0)
        return [me]
    return g


def _g528090(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x529cd0, 1, this=True, ret=r.getrandbits(32))
    me = rnd(c, 0x1d00)
    c.emu.wbytes(me + 0x8d, r.choice([0, 1, 2, 3, 0xffffffff]).to_bytes(4, 'little'))
    c.emu.wbytes(me + 0x91, r.choice([0, 1, 2, 3, 0xfffffffe]).to_bytes(4, 'little'))
    return [me]


def _g62f340(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x634d22, 3, pop=0, ret=r.getrandbits(32))
    a = rnd(c, 0x30)
    p = rnd(c, 0x30)
    c.emu.w32(a + 0x1c, p)
    n = r.choice([0, 1, 5, 100, 0x80000000, 0xffffffff])
    c.emu.w32(p + 0x14, n)
    c.emu.w32(a + 0x10, r.choice([0, 1, 5, 6, 100, 200, 0x80000000, 0xffffffff, 0x7fffffff]))
    return [a]


def _g4cd690(c):
    clear_hooks(c)
    r = c.rng
    blk = rnd(c, 0x40)
    hook_rec(c, 0x41e290, 1, pop=0, ret=blk)
    hook_rec(c, 0x4cd540, 1, this=True, ret=r.getrandbits(32))
    s = rnd(c, 0x30)
    n = r.choice([0, 1, 3, 10])
    c.emu.wbytes(s, bytes(r.randrange(1, 256) for _ in range(n)) + b'\0')
    return [rnd(c, 0x20), s]


S(0x63ade0, 'GUESS skip dead nodes then forward', 'thiscall', None, ret='eax', gen=_walker(0x63b440, 0x63b050), note='batch34112')
S(0x6483e0, 'GUESS skip dead nodes then forward B', 'thiscall', None, ret='eax', gen=_walker(0x63b3c0, 0x648690), note='batch34112')
S(0x528090, 'GUESS init two arrays of elements', 'thiscall', None, ret=None, gen=_g528090, note='batch34112')
S(0x62f340, 'GUESS move bytes between descriptors', 'cdecl', None, ret=None, gen=_g62f340, note='batch34112')
S(0x4cd690, 'GUESS duplicate string then call', 'thiscall', None, ret='eax', gen=_g4cd690, note='batch34112')
