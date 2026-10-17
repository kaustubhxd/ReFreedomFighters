"""specs_s242001.py - hand specs for tier-3 thunks and vtable-slot siblings (Sonnet-w4b)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, seh_record, seh_chain


def _pre(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x7003b0, pystub(c, 0, ret=lambda emu, k: r.getrandbits(32)))
    return r, c.emu, (lambda emu, k: r.getrandbits(32))


def g46ba90(c):
    r, em, R = _pre(c)
    hook_rec(c, 0x46b800, 2, ret=R, this=True)
    return [rnd(c, 0x40), r.getrandbits(32), r.getrandbits(32)]


def g4bcd60(c):
    r, em, R = _pre(c)
    hook_rec(c, 0x4c1a00, 1, ret=R, this=True)
    return [rnd(c, 0x40), r.getrandbits(32)]


def g41e010(c):
    r, em, R = _pre(c)
    em.w32(0x6fcd78, pystub(c, 2, ret=R, pop=8, this=True))
    return [rnd(c, 0x40), r.getrandbits(32), r.getrandbits(32)]


def g4f9b90(c):
    r, em, R = _pre(c)
    hook_rec(c, 0x4f9af0, 0, ret=R, this=True)
    swap = {}

    def to_vt2(emu, k):
        if swap['go']:
            emu.w32(swap['this'], swap['vt2'])
    vt1 = {0x36c: pystub(c, 1, ret=R, this=True, side=to_vt2), 0x358: pystub(c, 0, ret=R, this=True)}
    THIS = obj(c, 0xb0, vt1)
    vt2 = c.emu.alloc(0x400, 4)
    em.w32(vt2 + 0x358, pystub(c, 0, ret=R, this=True))
    em.w32(vt2 + 0x36c, pystub(c, 1, ret=R, this=True))
    swap.update(go=r.random() < 0.5, this=THIS, vt2=vt2)
    return [THIS]


def g4afed0(c):
    r, em, R = _pre(c)
    st = {}

    def s138(emu, k):    # the first call changes the field read afterwards and A's vtable
        if r.random() < 0.5:
            emu.w32(st['this'] + 0x44, r.getrandbits(32))
        if r.random() < 0.4:
            emu.w32(st['A'], st['vtA2'])
    A = obj(c, 0x100, {0x4c: pystub(c, 2, ret=R, this=True)})
    vtA2 = c.emu.alloc(0x100, 4)
    em.w32(vtA2 + 0x4c, pystub(c, 2, ret=R, this=True))
    sysobj(c, table_slots={0x138: pystub(c, 0, ret=A, this=True, side=s138), 0x4c: pystub(c, 1, ret=R, this=True)})
    THIS = rnd(c, 0x60)
    st.update(this=THIS, A=A, vtA2=vtA2)
    return [THIS]


def g4d29d0(c):
    r, em, R = _pre(c)

    def mm(e, rr):
        d, s, n = e.arg32(0), e.arg32(1), e.arg32(2)
        e.calllog.append(('mm', d, s, n))
        e.wbytes(d, e.rbytes(s, n))   # memmove semantics (rbytes copies first)
        e.ret(eax=d, argbytes=0)
    em.stub_import('memmove', mm)
    n = r.choice([0, 1, 1, 2, 3, 5, 8])
    recs = b''
    for i in range(n):
        size = 5 + r.choice([0, 0, 1, 2, 3, 7, 12])
        body = bytes(r.getrandbits(8) for _ in range(size))
        flag = r.choice([0, 1, 1, 2, 0x80, 0xff])
        recs += size.to_bytes(4, 'little') + bytes([flag]) + body[5:]
    total = len(recs)
    buf = rnd(c, total + 16)
    em.wbytes(buf, recs)
    THIS = rnd(c, 0x20)
    em.w32(THIS + 8, buf)
    used = total if (r.random() < 0.8 or total < 2) else r.randrange(1, total)
    em.w32(THIS + 0xc, used)
    return [THIS]


S(0x46ba90, 'GUESS thunk to 0x46b800', 'thiscall', None, ret='eax', gen=g46ba90, note='batch242001')
S(0x4bcd60, 'GUESS thunk to 0x4c1a00', 'thiscall', None, ret='eax', gen=g4bcd60, note='batch242001')
S(0x41e010, 'GUESS jump through [0x6fcd78]', 'thiscall', None, ret='eax', gen=g41e010, note='batch242001')
S(0x4f9b90, 'GUESS init then vslot 0x36c/0x358', 'thiscall', None, ret='eax', gen=g4f9b90, note='batch242001')
S(0x4afed0, 'GUESS table slot 0x138 then 0x4c twice', 'thiscall', None, ret='eax', gen=g4afed0, note='batch242001')
S(0x4d29d0, 'GUESS compact records', 'thiscall', None, ret=None, gen=g4d29d0, note='batch242001')
