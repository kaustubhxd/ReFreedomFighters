"""Relay-list dispatch. List slots are explicit iterator stand-ins. The stack
iterator's three words before/after every call are logged, not masked away;
receiver, ordered ids, unsigned message and payload pointer are compared too."""
from pilot import S

def _gen(c):
    r, em = c.rng, c.emu
    ids = [r.getrandbits(32) for _ in range(r.randrange(9))]
    cookie = r.getrandbits(32)
    def begin(e, _):
        p = e.arg32(0)
        for i, v in enumerate((0, 0, cookie)): e.w32(p + i * 4, v)
        e.calllog.append(('begin', e.reg('ecx'), tuple(e.r32(p + i * 4) for i in range(3))))
        e.ret(eax=0, argbytes=4)
    def nxt(e, _):
        p = e.arg32(0)
        before = tuple(e.r32(p + i * 4) for i in range(3))
        index = before[1]
        e.w32(p, int(index < len(ids)))
        e.w32(p + 4, index + 1)
        value = ids[index] if index < len(ids) else 0
        e.calllog.append(('next', e.reg('ecx'), before, tuple(e.r32(p + i * 4) for i in range(3)), value))
        e.ret(eax=value, argbytes=4)
    vt = em.fake_vtable('relay-list', 0x60 // 4, {0x4c: begin, 0x5c: nxt})
    m = em.alloc(0x20, 4); em.w32(m, vt)
    sinkvt = em.logging_vtable('relay-list-sink', 0x130, argwords={0x12c: 3})
    sink = em.alloc(0x20, 4); em.w32(sink, sinkvt)
    me = em.alloc(0x60, 4); em.wbytes(me, bytes(r.getrandbits(8) for _ in range(0x60)))
    em.w32(me + 0x4c, 0 if r.random() < 1 / 7 else m)
    em.w32(me + 0x44, sink)
    payload = em.alloc(0x20, 4)
    return [me, payload]
S(0x4b8ab0, 'ZRelayMessageList::RelayMessage', 'thiscall', None, ret=None, gen=_gen,
  note='Explicit list-iterator and dispatcher virtual stand-ins; all iterator out words and forwarded pointer arguments logged.')
