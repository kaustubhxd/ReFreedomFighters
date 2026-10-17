"""specs_s244021.py - Sonnet-w4c batch 244021: 0x6619d0 mesh test (hand port)."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, seh_record, seh_chain


def g6619d0(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    so = sysobj(c)
    inner = rnd(c, 0x40)
    B = rnd(c, 0x800)
    em.w32(so + 0x1aa3, inner)
    em.w32(inner + 0x20, B)
    # vertex block at B+0x300 (8 vertices of 36 bytes), index list at B+0x500
    vb = 0x300
    ilist = 0x500
    ngroups = r.choice([0, 1, 2, 3])
    data = bytearray()
    data += ngroups.to_bytes(2, 'little')
    for _ in range(ngroups):
        n = r.choice([2, 3, 4, 5])
        data += n.to_bytes(2, 'little')
        for _ in range(n):
            data += r.randrange(0, 8).to_bytes(2, 'little')
    em.wbytes(B + ilist, bytes(data))
    nodes = [0x10, 0x100, 0x200]
    r.shuffle(nodes)
    chain = nodes[:r.choice([0, 1, 2, 3])]
    for j, nd in enumerate(chain):
        em.w32(B + nd + 8, chain[j + 1] if j + 1 < len(chain) else 0)
        em.w32(B + nd + 0x2c, r.choice([0, 1, 2, 3, 0x80, r.getrandbits(32)]))
        em.w32(B + nd + 0x14, vb)
        em.w32(B + nd + 0x3c, ilist)

    def wvec(emu, k):
        emu.calllog.append(('src', emu.reg('edx')))
        emu.wbytes(emu.reg('ecx'), bytes(r.getrandbits(8) for _ in range(12)))
    hook_rec(c, 0x4e0d40, 1, ret=r.getrandbits(32), pop=4, this='mark', side=wvec)
    hit = r.choice([-1, -1, 0, 1, 2, 5])

    def sd(emu, k):
        emu.calllog.append(('edx', emu.r32(emu.reg('edx')) if False else bytes(emu.rbytes(emu.reg('edx'), 0x24)), emu.reg('ecx')))
    hook_rec(c, 0x4dddf0, 3, ret=lambda emu, k: (1 if k == hit else r.choice([0, 0x100])), pop=12, side=sd)
    a3 = rnd(c, 0x40)
    sc = em.alloc(16, 4)
    em.wbytes(sc, b''.join(struct.pack('<f', r.choice([0.0, 1.0, 2.0, -3.5, 0.25])) for _ in range(3)))
    node = r.choice([0, chain[0] if chain else 0, chain[0] if chain else 0])
    return [node, r.choice([0, 1, 2, 0xff, 0x81, r.getrandbits(32)]), r.getrandbits(32), a3, sc]


S(0x6619d0, 'GUESS ray vs mesh triangle strips', 'stdcall', None, ret='al', gen=g6619d0, note='batch244021')


def g661000(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    from unicorn.x86_const import UC_X86_REG_EDX
    seh_chain(c, r.choice([0, 1, 2]))
    sr = [seh_record(c, 2) for _ in range(10)]
    def t64(emu, k):
        emu.mu.reg_write(UC_X86_REG_EDX, r.getrandbits(32))
    sysobj(c, slots={0x1c8: pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), this=True, side=lambda emu, k: (t64(emu, k), sr[0](emu, k)))})

    def strncmp(e, rr):
        n = e.arg32(2)
        a = bytes(e.rbytes(e.arg32(0), 0x20)).split(b'\0')[0][:n]
        b = bytes(e.rbytes(e.arg32(1), 0x20)).split(b'\0')[0][:n]
        e.calllog.append(('strncmp', a, b))
        e.ret(eax=(0 if a == b else 1), argbytes=0)

    def strncpy(e, rr):
        d, s_, n = e.arg32(0), e.arg32(1), e.arg32(2)
        src = bytes(e.rbytes(s_, 0x20)).split(b'\0')[0][:n]
        e.wbytes(d, src + bytes(n - len(src)))
        e.calllog.append(('strncpy', src, n))
        e.ret(eax=d, argbytes=0)
    em.stub_import('strncmp', strncmp)
    em.stub_import('strncpy', strncpy)
    names = [b'', b'a', b'ab', b'abc', b'x' * 18 + b'a', b'x' * 18 + b'b']
    nm = em.alloc(48, 4)
    em.wbytes(nm, r.choice(names) + b'\0' + bytes(16))
    parent = rnd(c, 0x20)     # [this+0x10]: a record pointer (rec = parent as +8 block)
    curpar = parent + 8 if r.random() < 0.8 else 0
    recs = []
    for _ in range(r.choice([0, 1, 2, 3])):
        rec = rnd(c, 0x210)
        em.wbytes(rec + 0x1b8, r.choice(names) + b'\0' + bytes(8))
        em.w32(rec + 0x1cc, curpar if r.random() < 0.7 else r.getrandbits(32))
        recs.append(rec)
    fresh = rnd(c, 0x210)
    # list object stubs: slot 0x4c(&it) init, slot 0x64(&it) returns recs[k]-8 per call, 0x94, 0x8c, 4
    q = rnd(c, 0x20)
    lst = obj(c, 0x100, {
        0x4c: pystub(c, 1, ret=0, this=True, nullflag=(0,), side=sr[1]),
        0x64: pystub(c, 1, ret=lambda emu, k: (recs[k] - 8) if k < len(recs) else 0, this=True, nullflag=(0,), side=sr[2]),
        0x94: pystub(c, 1, ret=lambda emu, k: q if r.random() < 0.5 else 0, this=True, side=sr[3]),
        0x8c: pystub(c, 2, ret=lambda emu, k: fresh - 4, this=True, side=sr[4]),
        4: pystub(c, 1, ret=lambda emu, k: fresh - 4, this=True, side=sr[5])})
    created = obj(c, 0x100, {0x4c: pystub(c, 1, ret=0, this=True, nullflag=(0,), side=sr[1]),
                             0x64: pystub(c, 1, ret=0, this=True, nullflag=(0,), side=sr[2]),
                             4: pystub(c, 1, ret=lambda emu, k: fresh - 4, this=True, side=sr[5]),
                             0x94: pystub(c, 1, ret=0, this=True, side=sr[3])})
    hook_rec(c, 0x41e290, 1, ret=rnd(c, 0x30), pop=0, side=sr[6])
    hook_rec(c, 0x4cca60, 2, ret=created, pop=8, this=True, side=sr[7])
    me = rnd(c, 0x40)
    em.wbytes(me + 0x20, bytes([r.choice([0, 0, 0, 1])]))
    em.w32(me + 0x18, lst if r.random() < 0.7 else 0)
    em.w32(me + 0x10, curpar)
    return [me, r.choice([0, 1, r.getrandbits(32)]), r.choice([0, 1, r.getrandbits(32)]), nm]


S(0x661000, 'GUESS profiler record find or create (SEH)', 'thiscall', None, ret=None, gen=g661000, note='batch244021')
