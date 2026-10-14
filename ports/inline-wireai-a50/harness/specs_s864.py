"""specs_s864.py - area 50, batch 864: 0x4cef90 (name GUESS), thiscall, one stack arg (a record pointer), ret 4.
The C library moves (memcpy at import slot 0x67626c, memset at 0x676260) are stubs that do the copy and log (dst, src, n).
The segment's vt +0x7c is logged. The logger (0x700390) has a vt +0x24 (cdecl), logged. The node has count +8, next +0 and a
data area at +0x10; the record has a pointer chain at +0, a count at +4 and a flag at +8; all are generated so the moves stay
inside the node's data."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng
    only_hooks(c, {})

    def mv_memcpy(e, rr):
        d, s, n = e.arg32(0), e.arg32(1), e.arg32(2)
        e.calllog.append(('memcpy', d, s, n))
        if n:
            e.wbytes(d, e.rbytes(s, n))
        e.ret(eax=d, argbytes=0)

    def mv_memset(e, rr):
        d, v, n = e.arg32(0), e.arg32(1), e.arg32(2)
        e.calllog.append(('memset', d, v & 0xff, n))
        if n:
            e.wbytes(d, bytes([v & 0xff]) * n)
        e.ret(eax=d, argbytes=0)

    e.stub_import('memcpy', mv_memcpy)
    e.stub_import('memset', mv_memset)

    def v7c(e, rr):
        e.calllog.append(('seg.7c', e.arg32(0)))
        e.ret(eax=0, argbytes=4)

    def l24(e, rr):
        e.calllog.append(('log.24', e.arg32(0), e.arg32(1)))
        e.ret(eax=0, argbytes=0)

    logger = vt_object(c, 0x40, {0x24: l24}, nslots=0x40, name='logger')
    e.w32(0x700390, logger)

    seg = vt_object(c, 0x40, {0x7c: v7c}, nslots=0x100, name='seg')
    node = rnd(c, 0x100)
    nval = r.randint(0, 3)                      # the count the call removes (set below)
    cnt = nval if r.random() < 0.5 else r.randint(4, 8)   # equal counts reach the node-exhausted paths
    e.w32(node + 8, cnt)
    nxt = r.choice([0, 0, rnd(c, 0x100)])
    e.w32(node + 0, nxt)
    e.w32(seg + 8, node)
    e.w32(seg + 0x10, r.randint(0, 5))
    e.w32(seg + 0x14, r.choice([0, 1, 2]))
    e.w32(seg + 0x18, nval)
    e.w32(seg + 4, r.getrandbits(32))
    # the record: a chain pointer cell whose value is a data address of the node
    cell = rnd(c, 0x10)
    e.w32(cell, node + 0x10 + 4 * r.randint(0, 3))
    rec = rnd(c, 0x20)
    e.w32(rec + 0, cell if r.random() < 0.7 else (r.choice([0, node]) or cell))
    e.w32(rec + 4, r.randint(0, 3))
    e.w32(rec + 8, r.choice([0, 1, 2, -1 & 0xffffffff]))
    return [seg, rec]


S(0x4cef90, 'Fn4cef90 (GUESS name)', 'thiscall', None, gen=_gen, note='area50 batch864')
