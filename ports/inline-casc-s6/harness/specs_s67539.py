"""specs_s67539.py - cascade s6 batch 67539 (0x646fb0, thiscall(outMat, outVec, idx, obj) ret 0x10, returns al). this[0x11] bounds idx (unaligned dword), this[0x295] selects the fallback path;
sys[0x1aa3][0x18] has slots 0xc0 (matrix table: random float block) and 0xbc, sys[0x190f] slot 0x20 returns the pose manager that 0x63ea50 (hook) maps to a pose block (0x30-byte entries, or
0); obj slot 0x280 fills a local buffer; 0x646f30 is a hook (arg 0 stack-marked); 0x4dfd10 / 0x4de480 (matrix helpers) run unhooked."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g646fb0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    tabm = e.alloc(0x200, 4)
    e.wbytes(tabm, bytes(r.getrandbits(8) for _ in range(0x200)))
    rr = rnd(c, 0x40)
    mg = obj(c, 0x20, {0xc0: pystub(c, 1, this=True, ret=lambda em, k: tabm), 0xbc: pystub(c, 1, this=True, ret=lambda em, k: rr)})
    pm = obj(c, 0x20, {0x20: pystub(c, 0, this=True, ret=lambda em, k: 0x7777)})
    p = obj(c, 0x40, {})
    _w(c, p + 0x18, mg)
    pose = e.alloc(0x200, 4)
    e.wbytes(pose, bytes(r.getrandbits(8) for _ in range(0x200)))
    so = sysobj(c)
    _w(c, so + 0x1aa3, p)
    _w(c, so + 0x190f, pm)
    hook_rec(c, 0x63ea50, 1, this=True, ret=lambda em, k: r.choice([pose, pose, 0]))
    hook_rec(c, 0x646f30, 5, this=True, stackmark=(0, 3, 4), ret=0)
    ow = rnd(c, 0x80)
    _w(c, ow + 0x6c, r.getrandbits(32))
    o = obj(c, 0x40, {0x280: pystub(c, 1, this=True, stackmark=(0,))})
    _w(c, o + 8, ow)
    t = rnd(c, 0x300)
    _w(c, t + 0x11, r.choice([0, 1, 2, 3, 5]))
    _w(c, t + 0x295, r.choice([0, 1, 0x100]), 1)
    outm = rnd(c, 0x30)
    outv = rnd(c, 0x10)
    return [t, outm, outv, r.choice([0, 1, 2, 3, 4, 5, 6]), o]


S(0x646fb0, 'GUESS pose_matrix_for_index', 'thiscall', None, ret='al', gen=_g646fb0, note='batch67539')
