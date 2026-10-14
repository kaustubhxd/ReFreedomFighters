"""specs_s37039.py - cascade s6 batch 37039: 0x402320 (cdecl(s, b)). Hooked: 0x401890, 0x410bc0, 0x410de0 (returns scripted values by call index), 0x401820 (first call returns
the pointer array, later calls buffers). Setup tables V (via s+0x40 -> +4 -> +0x1c), entry W (V+0x24+idx*4), per-mode decoder table at 0x6f1dd8 whose structs carry a cdecl
stub at +0x1c."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g402320(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    hook_rec(c, 0x401890, 1, pop=0)
    hook_rec(c, 0x410bc0, 3, pop=0)
    idx = r.choice([0, 1, 2, 3])
    first = r.choice([0, 0, 0, 1, 5])
    e_val = r.choice([0, 1, 2])
    script = [first, idx if r.random() > 0.08 else 0xffffffff, r.getrandbits(32), r.choice([r.getrandbits(32), 0xffffffff])]

    def rd(em, k):
        return script[k] if k < len(script) else 0
    hook_rec(c, 0x410de0, 2, pop=0, ret=rd)
    cnt = r.choice([0, 1, 2, 3])
    arr = e.alloc(0x40, 4)
    bufs = [rnd(c, 0x20) for _ in range(8)]

    def al(em, k):
        return arr if k == 0 else bufs[k % 8]
    hook_rec(c, 0x401820, 2, pop=0, ret=al)
    # tables
    V = rnd(c, 0x200)
    modes = []
    for i in range(3):
        m = rnd(c, 0x40)
        e.w32(m + 0x1c, pystub(c, 2, pop=0, ret=lambda em, k: r.getrandbits(32)))
        modes.append(m)
        e.w32(0x6f1dd8 + 4 * i, m)
    for i in range(4):
        W = rnd(c, 0x20)
        e.w32(W, e_val if i == idx else r.choice([0, 1, 2]))
        e.w32(W + 0xc, r.randrange(3))
        e.w32(V + 0x24 + 4 * i, W)
    for i in range(3):
        e.w32(V + 4 * i, r.getrandbits(32) & 0xffff)
        e.w32(V + 0x124 + 4 * i, r.randrange(3))
    P = rnd(c, 0x40)
    e.w32(P + 0x1c, V)
    e.w32(P + 4, cnt)
    Q = rnd(c, 0x80)
    e.w32(Q + 0x34, r.choice([1, 2, 3]))
    ent = e.alloc(0x20, 4)
    for i in range(4):
        e.w32(ent + 4 * i, r.getrandbits(32))
    e.w32(Q + 0x38, ent)
    Tm = rnd(c, 0x80)
    e.w32(Tm + 4, P)
    e.w32(Tm + 0x68, Q)
    s = rnd(c, 0x60)
    e.w32(s + 0x40, Tm)
    b = rnd(c, 0x30)
    e.w32(b + 0x18, r.choice([0, 1, 2, 3, 100, 0xffffffff]))
    e.w32(b + 0x1c, r.choice([0, 1, 0xffffffff]))
    return [s, b]


S(0x402320, 'GUESS per-block setup', 'cdecl', None, ret='eax', gen=_g402320, note='batch37039')
