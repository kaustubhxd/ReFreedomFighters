"""specs_s37000.py - cascade s6 batch 37000: 0x498cc0 (bit set walk over 0x70-byte entries). 0x499360 hooked (thiscall, 2 args, may rewrite a bit byte);
set object has vtable slots 2 (1 arg) and 4 (2 args, deref'd first dword)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g498cc0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ah = e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32))))
    e.w32(0x7003b0, ah)
    cnt = r.choice([0, 1, 1, 2, 3, 5])
    so = sysobj(c, table_size=0xb00)
    tab = e.r32(so + 0x9b)
    e.w32(tab + 0xadc, rnd(c, 0x10))
    reg = e.alloc(cnt * 0x380 + 0x100, 4)
    nodes = []
    for _ in range(4):
        nodes.append(rnd(c, 0x60))
    for k, n in enumerate(nodes):
        e.w32(n + 0x50, nodes[k + 1] if k + 1 < len(nodes) and r.random() < 0.6 else 0)
    for j in range(cnt * 8):
        ent = reg + 0x70 * j
        e.wbytes(ent, bytes(r.getrandbits(8) for _ in range(0x70)))
        fl = e.r32(ent + 0x3c)
        fl = (fl | 0x4000000) if r.random() < 0.5 else (fl & ~0x4000000)
        e.w32(ent + 0x3c, fl & 0xffffffff)
        e.w32(ent + 0x50, 0 if r.random() < 0.4 else r.choice(nodes))
    holder = rnd(c, 0x10)
    e.w32(holder + 4, reg)
    me = rnd(c, 0x40)
    e.w32(me + 0x14, holder)
    bits = bytes(r.choice([0, 0xff, r.getrandbits(8), r.getrandbits(8)]) for _ in range(max(cnt, 1) + 8))
    arr = e.alloc(len(bits) + 8, 4)
    e.wbytes(arr, bits)

    def side(em, k):
        if cnt and r.random() < 0.5:
            em.wbytes(arr + r.randrange(cnt), bytes([r.getrandbits(8)]))
    hook_rec(c, 0x499360, 2, this=True, side=side)
    strm = obj(c, 0x20, {0x8: pystub(c, 1, this=True), 0x10: pystub(c, 2, this=True, deref={0: 1})})
    so2 = rnd(c, 0x20)
    e.w32(so2, strm)
    e.w32(so2 + 8, arr)
    e.w32(so2 + 0xc, cnt)
    return [me, so2]


S(0x498cc0, 'GUESS walk bit set entries, clear or chain', 'thiscall', None, ret=None, gen=_g498cc0, note='batch37000')
