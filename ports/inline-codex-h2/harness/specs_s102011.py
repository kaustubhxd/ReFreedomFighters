import struct
from pilot import S
from recruits_util import obj, rnd, sysobj, clear_hooks, hook_rec, pystub


def _bits(v):
    return struct.unpack('<I', struct.pack('<f', float(v)))[0]


def gen(c):
    clear_hooks(c)
    e, r = c.emu, c.rng
    idx = r.randrange(3)
    data = rnd(c, 0x80)
    for i in range(6):
        e.w32(data + i*0x1c, r.getrandbits(32))
    args = rnd(c, 0x40)
    e.w32(args + 0x10, data)
    e.w32(args + 0x14, r.choice([0x400, 0, 0x800, 0xc00]))
    val = float('nan') if r.randrange(4) == 0 else r.uniform(-2.0, 2.0)
    e.w32(args + 4, 0x7fc00000 if val != val else _bits(val))

    config = rnd(c, 0x40)
    e.w32(config + 0x14, r.choice([0x800, 0, 0x1000]))
    records = rnd(c, 0x100)
    e.w32(records + idx*0x18 + 4, r.choice([1, 0, 2, 3]))
    e.w32(records + idx*0x18 + 0x14, config)

    count_stub = pystub(c, 0, ret=r.getrandbits(32), pop=0, this=True)
    update_stub = pystub(c, 2, ret=0, pop=8, this=True)
    vt = e.alloc(0x350, 4)
    e.w32(vt + 0x2cc, count_stub)
    e.w32(vt + 0x340, update_stub)
    me = rnd(c, 0x120)
    e.w32(me, vt)
    e.w32(me + 0x1c, records)
    e.w32(me + 0x5c, rnd(c, 0x20))
    e.w32(me + 0x5c, obj(c, 0x40, {}))

    rand_values = [r.uniform(-1.0, 1.0)]
    mgr_b8 = pystub(c, 1, ret=r.getrandbits(32), pop=4, this=True)
    mgr_ac = pystub(c, 2, ret=0, pop=8, this=True)
    system_slot_owner = obj(c, 0x200, {0xb8: mgr_b8, 0xac: mgr_ac})
    so = sysobj(c)
    e.w32(so + 0x190f, system_slot_owner)
    e.w32(so + 0x40, r.getrandbits(32))

    service_stub = None
    vec = [_bits(r.uniform(-1.0, 1.0)) for _ in range(4)]
    dest = [_bits(r.uniform(-1.0, 1.0)) for _ in range(3)]
    def set_matrix_args(emu, k):
        p = emu.arg32(3)
        out = emu.arg32(2)
        for i, x in enumerate(vec): emu.w32(p + 4*i, x)
        for i, x in enumerate(dest): emu.w32(out + 4*i, x)
    service_stub = pystub(c, 5, ret=0, pop=20, this=True,
                          nullflag=(2, 3), side=set_matrix_args)
    svc = obj(c, 0x20, {0xc: service_stub})
    e.w32(me + 0x5c, svc)

    e.w32(0x6f5630, r.getrandbits(32))
    e.w32(0x7003b0, pystub(c, 0, ret=r.getrandbits(32), pop=0))
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0)
    return [me, r.getrandbits(32), r.getrandbits(32), idx, args]


S(0x464bd0, 'GUESS_update_indexed_flag_and_transform', 'thiscall', None,
  ret='al', gen=gen, note='batch102011')
