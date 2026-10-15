"""specs_s67518.py - cascade s6 batch 67518 (0x468fa0, thiscall(stream) ret 4, returns 1). The stream's read slot 0x18 logs every call and writes scripted dwords (A with bit 3 set or
not, B random) into stack destinations and random dwords into heap ones; this slots 0x64 / 0x68; the table object's embedded registry at +0xcc (vtable pointer at +0xcc, slots 8 / 4 / 0,
this = the table object + 0xcc); 0x41e680 is a hook."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g468fa0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    A = r.choice([0, 8, 8, 0x18, 7, r.getrandbits(32)])
    B = r.getrandbits(32)
    cnt = {'stack': 0}

    def rdside(em, k):
        d = em.arg32(0)
        heap = 0x20000000 <= d < 0x30000000
        em.calllog.append(('rd', d if heap else 1, em.arg32(1)))
        if heap:
            em.w32(d, 0x11110000 + k)
        else:
            em.w32(d, A if cnt['stack'] == 0 else B)
            cnt['stack'] += 1
    stream = obj(c, 0x20, {0x18: pystub(c, 2, this=True, stackmark=(0,), side=rdside)})
    so = sysobj(c, table_size=0x100)
    tab = int.from_bytes(e.rbytes(so + 0x9b, 4), 'little')
    vt = e.alloc(0x20, 4)
    cur = r.choice([0, 1, 5])
    found = r.choice([0, 0x777, 0x888])
    e.w32(vt + 8, pystub(c, 0, this=True, ret=cur))
    e.w32(vt + 4, pystub(c, 1, this=True, ret=found))
    e.w32(vt + 0, pystub(c, 2, this=True))
    e.w32(tab + 0xcc, vt)
    hook_rec(c, 0x41e680, 0, this=True, ret=lambda em, k: r.getrandbits(32))
    t = obj(c, 0x40, {0x64: pystub(c, 1, this=True), 0x68: pystub(c, 2, this=True)})
    return [t, stream]


S(0x468fa0, 'GUESS load_header', 'thiscall', None, ret='al', gen=_g468fa0, note='batch67518')
