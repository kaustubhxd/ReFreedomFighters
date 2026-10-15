"""specs_s743.py - ZItemWeapon::Save (area 72). The item is a random block with byte, dword and float fields at the offsets
the exe reads. The save object and a second writer (returned by slots 0x60 / 0x44 / 0x3c / 0x4c, so the chained writes are
checked) log each slot with its arguments. ZItem::Save (0x4705a0) is hooked (logged)."""
import struct
from pilot import S
from specs_s701 import _rnd
from specs_s705 import nostk

BYTE_FIELDS = (0xbe, 0xbf, 0xc8, 0xc9, 0xca, 0xcb, 0xcc)
FLOAT_FIELDS = (0xd1,)
DWORD_FIELDS = (0xb6, 0xba, 0xc0, 0xc4, 0xd5, 0xdd, 0xe5, 0xe1, 0xed, 0xfd, 0x101, 0xd9)


def _f(x):
    return struct.unpack('<f', struct.pack('<f', x))[0]


def _wsave(c):
    e = c.emu
    log = lambda name, off, args: e.calllog.append((name, off, nostk(e.reg('ecx')), tuple(nostk(a) for a in args)))

    item = _rnd(c, 0x200)
    for off in BYTE_FIELDS:
        e.wbytes(item + off, bytes([c.rng.getrandbits(8)]))
    for off in FLOAT_FIELDS:
        e.wbytes(item + off, struct.pack('<f', _f(c.rng.uniform(-500.0, 500.0))))
    for off in DWORD_FIELDS:
        e.w32(item + off, c.rng.getrandbits(32))

    def h_item(em, r):
        log('item', 0x4705a0, (em.arg32(0),))
        em.ret(eax=0, argbytes=4)
    e.hook(0x4705a0, h_item)

    sub = _rnd(c, 0x40)

    def writer(name, chain_slots):
        tbl = {}
        for s_ in (0x3c, 0x44, 0x4c, 0x60, 0x68, 0x6c):
            ret = sub if s_ in chain_slots else 0

            def f(em, r, s_=s_, ret=ret):
                log(name, s_, (em.arg32(0),))
                em.ret(eax=ret, argbytes=4)
            tbl[s_] = f
        return tbl

    chain = (0x3c, 0x44, 0x4c, 0x60)
    save = _rnd(c, 0x40)
    e.w32(save, e.fake_vtable('save', 0x100, writer('save', chain)))
    e.w32(sub, e.fake_vtable('sub', 0x100, writer('sub', chain)))
    return [item, save]


S(0x4707c0, 'ZItemWeapon::Save', 'thiscall', None, ret='al', gen=_wsave,
  note='b743 area 72 [high]; ZItem::Save hooked; chained writes checked via sub writer')
