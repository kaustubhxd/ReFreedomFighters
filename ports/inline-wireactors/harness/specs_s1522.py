"""specs_s1522.py - recruits thread batch 1522: CFormationControl::Save (0x5b7100).
The saver is a recorder: slot 0x10 (write ptr, size) appends (size, ptr, first 0x30 bytes) to a log in the heap, so
both runs are compared by every byte written, in order. The formation table, the member tables and the second tables
are REFTAB fakes (recruits_util.reftab, count + iteration); the records are random heap blocks."""
import struct
from pilot import S
from recruits_util import rnd, obj, reftab

LOG_ENTRIES = 512
ENTRY = 0x40


def _saver(c):
    e = c.emu
    log = e.alloc(ENTRY * LOG_ENTRIES + 8, 4)
    e.w32(log, 0)   # entry count

    def h(em, rr):
        ptr, size = em.arg32(0), em.arg32(1)
        n = em.r32(log)
        if n < LOG_ENTRIES:
            row = log + 8 + ENTRY * n
            em.w32(row, size)
            # heap pointers as they are; stack pointers (the caller's locals) as a marker: the two builds have
            # different frames, only the bytes written matter
            em.w32(row + 4, ptr if 0x20000000 <= ptr < 0x21000000 else 0x57ac0000)
            data = em.rbytes(ptr, min(size, 0x30)) if size else b''
            em.wbytes(row + 8, data)
            em.w32(log, n + 1)
        em.ret(0, 8)
    w = obj(c, 0x20, {0x10: e.stub_fn('save write', h)})
    return w, log


def _member(c):
    return rnd(c, 0x20)


def _gen(c):
    r = c.rng
    e = c.emu
    w, log = _saver(c)
    this = rnd(c, 0x100)
    e.w32(this + 4, r.getrandbits(32))
    fs = []
    for _ in range(r.randint(0, 3)):
        f = rnd(c, 0xa0)
        mem = [_member(c) for _ in range(r.randint(0, 3))]
        m_tab = reftab(c, mem, count=len(mem))
        e2 = [_member(c) for _ in range(r.randint(0, 3))]
        t2 = reftab(c, e2, count=len(e2))
        e.w32(f + 4, m_tab)
        e.w32(f + 8, t2)
        fs.append(f)
    tab = reftab(c, fs, count=len(fs))
    e.w32(this + 0x48, tab if r.random() < 0.95 else 0)
    return [this, w]


S(0x5b7100, 'CFormationControl::Save', 'thiscall', ret='al', gen=_gen, note='batch1522')
