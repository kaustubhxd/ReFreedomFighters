"""specs_s38041.py - cascade s8 batch 38041. Stream with logging slots (every call goes to the call log in order): typed reads 0x40 (4 bytes, a small random value so the blob length stays small), 0x68 (1 byte),
0x58 (2), 0x50 (4), 0x48 (2), 0x70 (8) write random data through the destination; slot 0x10 hands out a pointer to a heap blob through its out parameter. The entity has slots 0x88 / 0x80 (logged);
0x6352f0 (writes a random dword through its out pointer), the allocator 0x41e290 (random-filled blocks) and the memcpy 0x634d22 (real copy) are hooks; the object at 0x700334 has slot 0xc. Return is bool (AL)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec


def _g4b59f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    blob = e.alloc(0x80, 4)
    e.wbytes(blob, r.randbytes(0x80))

    def rd(slotn, width, small=False):
        def h(em, res_):
            dst = em.arg32(0)
            data = bytes(r.getrandbits(8) for _ in range(width))
            if small:
                data = (r.choice([0, 1, 3, 8, 0x10, 0x20])).to_bytes(4, 'little')
            em.calllog.append((slotn, em.reg('ecx')))
            em.wbytes(dst, data)
            em.ret(eax=0, argbytes=4)
        return e.stub_fn('rd%x' % slotn, h)

    def s10(em, res_):
        out, n = em.arg32(0), em.arg32(1)
        em.calllog.append(('s10', em.reg('ecx'), n))
        em.w32(out, blob)
        em.ret(eax=0, argbytes=8)
    def logger(name):
        def h(em, res_):
            em.calllog.append((name, em.reg('ecx'), em.arg32(0), em.r32(em.arg32(0)) if name == 's88' else 0))
            em.ret(eax=0, argbytes=4)
        return e.stub_fn(name, h)
    # slot 0x40 is used both for the fields and for the blob length: always a small value
    stream = obj(c, 0x80, {0x40: rd(0x40, 4, True), 0x68: rd(0x68, 1), 0x58: rd(0x58, 2), 0x50: rd(0x50, 4), 0x48: rd(0x48, 2),
                           0x70: rd(0x70, 8), 0x10: e.stub_fn('s10', s10), 0x80: logger('s80')})

    me = obj(c, 0x200, {0x88: logger('s88')})
    e.w32(me + 4, r.getrandbits(32))

    def side6352(em, k):
        em.w32(em.arg32(0), r.getrandbits(32))
    hook_rec(c, 0x6352f0, 1, this=True, pop=4, stackmark=(0,), side=side6352)

    def alloc(em, res_):
        n = em.arg32(0)
        em.calllog.append(('alloc', n))
        p = em.alloc(n + 0x20, 4)
        em.wbytes(p, r.randbytes(n + 0x20))
        em.ret(eax=p, argbytes=0)

    def memcpy(em, res_):
        d, s, n = em.arg32(0), em.arg32(1), em.arg32(2)
        em.calllog.append(('memcpy', d, s, n))
        em.wbytes(d, em.rbytes(s, min(n, 0x100)))
        em.ret(eax=d, argbytes=0)
    e.hook(0x41e290, alloc)
    e.hook(0x634d22, memcpy)
    def sc(em, res_):
        em.calllog.append(('sc', em.reg('ecx')))
        em.ret(eax=0, argbytes=0)
    e.w32(0x700334, obj(c, 0x20, {0xc: e.stub_fn('sc', sc)}))
    return [me, stream]


S(0x4b59f0, 'GUESS load entity block from stream', 'thiscall', None, ret='al', gen=_g4b59f0, note='batch38041')
