"""specs_s409.py - batch 409: ZBaseGeom::GetSize and ZBaseGeom::GetOwnerRoom (callees of ZPlayer::DebugControl)."""
from pilot import S
import fu_kit as K


def _size(c):
    return [K.rnd(c, 0x60), K.vec(c, 3, -100, 100, pad=0)]


def _room(c):
    r = c.rng
    e = c.emu
    K.hooks(c, {})
    rmo_slots = {}
    table = K.rnd(c, 0x70 * 8)
    ents = []
    for i in range(r.choice([0, 1, 3, 6])):
        ent = K.rnd(c, 0x20)
        e.wbytes(ent + 0x1c, bytes([r.choice([0, 1, 1, 255])]))
        if r.random() < 0.7:
            e.w32(ent, r.getrandbits(32))
        ents.append(ent)
    rmo_slots[0x4c] = K.fn(c, 'rmo.table', 0, ret=table)
    rmo_slots[0x5c] = K.fn(c, 'rmo.entry', 1, ret=lambda ee, a: ents[(a[0] - 1) % len(ents)] if ents and r.random() < 0.9 else 0)
    rmo = K.obj(c, 0x40, rmo_slots, 'rmo')
    default_room = K.rnd(c, 0x10)
    rm = K.rnd(c, 0x1000)
    e.w32(rm + 8, rmo)
    e.w32(rm + 0xadc, default_room)
    so = K.rnd(c, 0x1100)
    e.w32(so + 0x9b, rm)
    e.w32(0x70039c, so)
    # a fresh 1-based index table entry: the first dword of table entry idx-1 is its room
    for i in range(8):
        e.w32(table + 0x70 * i, r.getrandbits(32))
    self = K.rnd(c, 0x80)
    f = r.choice([0, 0x40000000, 0x40040000, 0x40000000 | 0x40040000, 0x00040000, 0x40000000 | 0x1])
    e.w32(self + 0x3c, f)
    e.w16(self + 0x5c, r.choice([0, 1, 2, 3, 8, 9, 0xffff]))
    # the room-record chain for the flagless case
    chain_nodes = []
    prev = None
    for i in range(r.choice([0, 1, 2, 3])):
        node = K.rnd(c, 0x60)
        room = K.rnd(c, 0x20)
        rec = K.rnd(c, 0x40)
        e.w32(rec + 0x23, 0x100021 if r.random() < 0.4 else r.getrandbits(32))
        e.w32(room + 0xc, rec)
        e.w32(node + 0x54, room if r.random() < 0.75 else 0)
        e.w32(node + 0x50, 0)
        if prev is not None:
            e.w32(prev + 0x50, node)
        chain_nodes.append(node)
        prev = node
    if chain_nodes:
        e.w32(self + 0x54, e.r32(chain_nodes[0] + 0x54))
        e.w32(self + 0x50, chain_nodes[0])
    else:
        e.w32(self + 0x54, 0)
        e.w32(self + 0x50, 0)
    return [self]


S(0x4db7c0, 'ZBaseGeom::GetSize', 'thiscall', None, ret=None, gen=_size, note='batch409')
S(0x4db3b0, 'ZBaseGeom::GetOwnerRoom', 'thiscall', None, ret='eax', gen=_room, note='batch409; page 0 reads as in the exe')
